#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int mapped[10];
  for (int i = 1; i <= 9; i++) scanf("%d", &mapped[i]);
  int l = 0;
  while (l < n && mapped[s[l] - '0'] <= s[l] - '0') l++;
  for (int i = l; i < n; i++) {
    if (mapped[s[i] - '0'] <= s[i] - '0') break;
    s[i] = mapped[s[i] - '0'] + '0';
  }
  cout << s << endl;
  return 0;
}
