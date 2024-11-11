#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e+9 + 7;
const double PI = acos(-1.0);
int ret[1000];
bool flag[1000];
void output(int n) {
  int ret = 0;
  for (int i = int(0); i < int(n); i++) {
    if (flag[i]) ret++;
  }
  cout << ret << "\n";
  for (int i = int(0); i < int(n); i++) {
    if (flag[i]) cout << (i + 1) << " ";
  }
  cout << "\n" << flush;
}
void invert(int n) {
  for (int i = int(0); i < int(n); i++) {
    flag[i] = !flag[i];
  }
}
void update(int n) {
  int in;
  for (int i = int(0); i < int(n); i++) {
    cin >> in;
    if (!flag[i]) ret[i] = (ret[i] < in ? ret[i] : in);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = int(0); i < int(n); i++) ret[i] = 1000000007;
  int w = 1;
  while (w * 2 < n) w *= 2;
  while (w) {
    int tcnt = 0;
    int cnt = 0;
    bool eflag = true;
    for (int i = int(0); i < int(n); i++) {
      flag[i] = eflag;
      cnt++;
      if (cnt == w) {
        cnt = 0;
        eflag = !eflag;
      }
    }
    output(n);
    update(n);
    invert(n);
    output(n);
    update(n);
    w /= 2;
  }
  cout << -1 << "\n";
  for (int i = int(0); i < int(n); i++) {
    cout << ret[i] << " ";
  }
  cout << "\n" << flush;
}
