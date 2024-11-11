#include <bits/stdc++.h>
using namespace std;
string s;
const int maxn = 2e5 + 10;
int rem[3], cnt = 0;
void get_input() { cin >> s; }
void solve() {
  for (int i = 0; i < s.size(); i++) {
    int kom = s[i];
    kom -= '0';
    kom %= 3;
    rem[kom]++;
    if (rem[0] == 1 || rem[1] == 3 || rem[2] == 3 ||
        rem[2] >= 1 and rem[1] >= 1) {
      ++cnt;
      fill(rem, rem + 3, 0);
    }
  }
}
void output() { cout << cnt; }
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  while (tc--) {
    get_input(), solve(), output();
  }
  return 0;
}
