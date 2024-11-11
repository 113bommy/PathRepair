#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MAXN = 333;
char buf[MAXN];
char ret[MAXN];
int n, dif, bnum;
void exit() { exit(0); }
int main() {
  for (int i = 0; i < 300; i++) cout << 'a';
  cout << endl;
  int x;
  cin >> x;
  if (!x) exit();
  for (int i = 0; i < 300; i++) cout << 'b';
  cout << endl;
  int y;
  cin >> y;
  if (!y) exit();
  n = 300 - x + 300 - y;
  bnum = 300 - y;
  for (int i = 0; i < n; i++) buf[i] = 'a';
  for (int i = n - 1; i > 0; i--) {
    buf[i] = 'b';
    cout << buf << endl;
    int d;
    cin >> d;
    if (!d) exit();
    if (d == dif + 1)
      ret[i] = 'a';
    else
      ret[i] = 'b';
    dif = d;
  }
  int cnt = 0;
  for (int i = 1; i < n; i++)
    if (ret[i] == 'b') cnt++;
  if (cnt != bnum)
    ret[0] = 'b';
  else
    ret[0] = 'a';
  cout << ret << endl;
  cin >> dif;
  return 0;
}
