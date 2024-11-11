#include <bits/stdc++.h>
using namespace std;
const int maxn = 26, inf = 1e9;
int n, ind, tmp[3];
long long a[maxn][3];
map<pair<int, int>, pair<int, int> > Left;
char c[3] = {'L', 'M', 'W'};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  int n1 = n / 2, pw = 1;
  for (int i = 0; i < n1; i++) pw *= 3;
  for (int i = 0; i < pw; i++) {
    for (int j = 0; j < 3; j++) tmp[j] = 0;
    int mask = i;
    for (int j = 0; j < n1; j++) {
      tmp[(mask % 3 + 1) % 3] += a[j][(mask % 3 + 1) % 3];
      tmp[(mask % 3 + 2) % 3] += a[j][(mask % 3 + 2) % 3];
      mask /= 3;
    }
    pair<int, int> in = make_pair(tmp[1] - tmp[0], tmp[2] - tmp[1]);
    if (Left.find(in) == Left.end())
      Left[in] = make_pair(tmp[0], i);
    else
      Left[in] = max(Left[in], make_pair(tmp[0], i));
  }
  int n2 = n - n1;
  pw = 1;
  for (int i = 0; i < n2; i++) pw *= 3;
  int ans = -inf;
  int mask1 = -1, mask2 = -1;
  for (int i = 0; i < pw; i++) {
    for (int j = 0; j < 3; j++) tmp[j] = 0;
    int mask = i;
    for (int j = n1; j < n; j++) {
      tmp[(mask % 3 + 1) % 3] += a[j][(mask % 3 + 1) % 3];
      tmp[(mask % 3 + 2) % 3] += a[j][(mask % 3 + 2) % 3];
      mask /= 3;
    }
    pair<int, int> in = make_pair(-tmp[1] + tmp[0], -tmp[2] + tmp[1]);
    if (Left.find(in) != Left.end()) {
      pair<int, int> tmpp = Left[in];
      if (tmp[0] + tmpp.first > ans) {
        ans = tmp[0] + tmpp.first;
        mask1 = i;
        mask2 = tmpp.second;
      }
    }
  }
  if (mask1 == -1)
    cout << "Impossible" << endl;
  else {
    for (int i = 0; i < n1; i++) {
      cout << c[(mask2 % 3 + 1) % 3] << c[(mask2 % 3 + 2) % 3] << endl;
      mask2 /= 3;
    }
    for (int i = 0; i < n2; i++) {
      cout << c[(mask1 % 3 + 1) % 3] << c[(mask1 % 3 + 2) % 3] << endl;
      mask1 /= 3;
    }
  }
}
