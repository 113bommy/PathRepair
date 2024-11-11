#include <bits/stdc++.h>
using namespace std;
int num[5][1000];
int mmax[5];
string a, b, c;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cin >> a >> b >> c;
  for (int i = 0; i < a.size(); i++) {
    num[1][a[i]]++;
    mmax[1] = max(num[1][a[i]], mmax[1]);
  }
  for (int i = 0; i < b.size(); i++) {
    num[2][b[i]]++;
    mmax[2] = max(num[2][b[i]], mmax[2]);
  }
  for (int i = 0; i < c.size(); i++) {
    num[3][c[i]]++;
    mmax[3] = max(num[3][c[i]], mmax[3]);
  }
  for (int i = 1; i <= 3; i++) {
    if (mmax[i] == a.size()) {
      if (n == 1) mmax[i] = a.size() - 1;
    } else if (mmax[i] + n > a.size()) {
      mmax[i] = a.size();
    } else
      mmax[i] += n;
  }
  if (mmax[1] > mmax[2] && mmax[1] > mmax[3])
    cout << "Kuro\n";
  else if (mmax[2] > mmax[3] && mmax[2] > mmax[1])
    cout << "Shiro\n";
  else if (mmax[3] > mmax[1] && mmax[3] > mmax[2])
    cout << "Katie\n";
  else
    cout << "Draw\n";
  return 0;
}
