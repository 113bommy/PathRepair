#include <bits/stdc++.h>
using namespace std;
template <class T, class... U>
void pr(T&& a, U&&... b) {
  cout << forward<T>(a);
  (int[]){(cout << forward<U>(b), 0)...};
}
template <class T, class... U>
void re(T&& a, U&&... b) {
  cin >> forward<T>(a);
  (int[]){(cin >> forward<U>(b), 0)...};
}
const int MAXN = 2e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
string s;
int ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  re(s);
  s = ' ' + s;
  for (int i = 1; i < s.size(); i++)
    if ((s[i] - '0') % 4 == 0) ans++;
  for (int i = 2; i < s.size(); i++)
    if (stoi(s.substr(i - 1, 2)) % 4 == 0) ans += i - 1;
  pr(ans, '\n');
}
