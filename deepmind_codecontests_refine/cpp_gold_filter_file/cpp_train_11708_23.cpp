#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
bitset<35> s[10];
int c[10];
set<int> correct_bits;
int ans = 0;
bool consistent(bitset<35>& code) {
  bool ans = true;
  for (int i = 1; i < m; i++) {
    ans &= __builtin_popcountll((code ^ s[i]).to_ullong()) + c[i] == n;
  }
  return ans;
}
void rb(int pos) {
  if (correct_bits.size() == c[0]) {
    bitset<35> code;
    for (int i = 0; i < n; i++) {
      if (correct_bits.count(i)) {
        code[i] = s[0][i];
      } else {
        code[i] = not s[0][i];
      }
    }
    if (consistent(code)) {
      ans++;
    }
  } else {
    for (int i = pos; i < n; i++) {
      correct_bits.insert(i);
      rb(i + 1);
      correct_bits.erase(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string bit_string;
    cin >> bit_string;
    s[i] = bitset<35>(bit_string);
    cin >> c[i];
  }
  rb(0);
  cout << ans << '\n';
  return 0;
}
