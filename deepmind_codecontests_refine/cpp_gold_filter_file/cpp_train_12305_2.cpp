#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve();
int main() {
  setup();
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
vector<int> to3(long long n) {
  vector<int> reversed;
  while (n) {
    reversed.push_back(n % 3);
    n /= 3;
  }
  return reversed;
}
long long toNumber(vector<int> &reversed) {
  long long n = 0;
  long long val = 1;
  for (int i = 0; i < reversed.size(); i++, val *= 3)
    if (reversed[i]) n += val;
  return n;
}
void solve() {
  long long n;
  cin >> n;
  vector<int> num = to3(n);
  int last0 = num.size();
  for (int i = num.size() - 1; i >= 0; i--) {
    if (num[i] == 0) {
      last0 = i;
    } else if (num[i] == 2) {
      if (last0 == num.size()) {
        num.push_back(1);
      } else
        num[last0] = 1;
      last0--;
      for (int j = last0; j >= 0; j--) num[j] = 0;
      break;
    }
  }
  cout << toNumber(num) << endl;
}
