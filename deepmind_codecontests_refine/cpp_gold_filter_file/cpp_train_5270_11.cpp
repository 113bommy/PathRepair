#include <bits/stdc++.h>
using namespace std;
using v_i = vector<int>;
bool isVowel(char curr) {
  if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
    return true;
  return false;
}
bool checkTypo(string& s, int i, int p) {
  char curr = s[i];
  if (isVowel(curr)) return false;
  int temp = i;
  i--;
  for (; i >= p; i--) {
    if (isVowel(s[i])) return false;
    if (s[i] != curr) {
      if (temp - i >= 2) return true;
      if (i > p && !isVowel(s[i - 1]))
        return true;
      else
        return false;
    }
  }
  return false;
}
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int pre_space = 0;
  for (int i = 0; i < n; i++) {
    if (checkTypo(s, i, pre_space)) {
      cout << ' ';
      pre_space = i;
    }
    cout << s[i];
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
