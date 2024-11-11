#include <bits/stdc++.h>
using namespace std;
const int MX = 4e5;
int n, opening = 0, mn = 1e9, mnBegin;
int sum[MX], SUM[MX], X[MX], Y[MX], x, y;
int cnt1[MX], cnt2[MX];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  for (int i = int(0); i < int(n); i++)
    if (s[i] == '(') opening++;
  if (opening != n / 2 || n % 2 == 1) {
    cout << 0 << endl;
    cout << "1 1" << endl;
    return 0;
  }
  for (int i = int(0); i < int(n); i++)
    sum[i] = (i == 0 ? 0 : sum[i - 1]) + (s[i] == '(' ? 1 : -1);
  for (int i = int(0); i < int(n); i++) mn = min(mn, sum[i]);
  for (int i = int(0); i < int(n); i++)
    if (sum[i] == mn) mnBegin = i;
  for (int i = int(0); i < int(n); i++) SUM[i] = sum[(i + mnBegin) % n] - mn;
  for (int i = int(0); i < int(n); i++)
    if (SUM[i] == 0) X[x++] = i;
  X[x++] = n;
  for (int i = int(0); i < int(n); i++)
    if (SUM[i] == 1) Y[y++] = i;
  cnt1[0] = 0;
  for (int i = int(0); i < int(n); i++)
    cnt1[i + 1] = cnt1[i] + int(SUM[i] == 1);
  cnt2[0] = 0;
  for (int i = int(0); i < int(n); i++)
    cnt2[i + 1] = cnt2[i] + int(SUM[i] == 2);
  tuple<int, int, int> ans(x - 1, 0, 0);
  for (int i = int(0); i < int(x - 1); i++)
    ans = max(ans, make_tuple(cnt1[X[i + 1]] - cnt1[X[i]], X[i] + 1, X[i + 1]));
  for (int i = int(0); i < int(y - 1); i++)
    if (SUM[Y[i + 1] + 1] != 0)
      ans = max(ans, make_tuple(x - 1 + cnt2[Y[i + 1]] - cnt2[Y[i]], Y[i] + 1,
                                Y[i + 1]));
  int ansA, l, r;
  tie(ansA, l, r) = ans;
  l = (l + n + mnBegin) % n;
  r = (r + n + mnBegin) % n;
  cout << ansA << endl << l + 1 << " " << r + 1 << endl;
}
