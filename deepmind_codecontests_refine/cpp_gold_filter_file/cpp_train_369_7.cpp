#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
long long Y0, Y1, a[N], b[N];
vector<int> ve[N], mice;
int choice[N], num[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> Y0 >> Y1;
  for (int i = (0); i < (n); i++) cin >> a[i];
  for (int i = (0); i < (m); i++) cin >> b[i];
  int cheese = 0;
  for (int i = (0); i < (n); i++) {
    while (cheese < m && b[cheese] < a[i]) cheese++;
    if (cheese < m && cheese > 0 && b[cheese] - a[i] == a[i] - b[cheese - 1]) {
      mice.push_back(i);
      choice[i] = cheese;
    } else if (cheese == m || (cheese < m && cheese > 0 &&
                               b[cheese] - a[i] > a[i] - b[cheese - 1])) {
      ve[cheese - 1].push_back(a[i] - b[cheese - 1]);
    } else {
      ve[cheese].push_back(b[cheese] - a[i]);
    }
  }
  for (int i = (0); i < (m); i++) {
    sort((ve[i]).begin(), (ve[i]).end());
    num[i] = !ve[i].empty();
    if (((int)(ve[i]).size()) >= 2 && ve[i][0] == ve[i][1]) num[i] = 2;
  }
  auto delta = [&](int cheese, int i) {
    if (ve[cheese].empty()) return 1;
    long long dist = abs(b[cheese] - a[i]);
    if (dist < ve[cheese][0])
      return 1 - num[cheese];
    else if (dist == ve[cheese][0])
      return 1 + num[cheese];
    else
      return 0;
  };
  auto upd = [&](int cheese, int i) {
    long long dist = abs(b[cheese] - a[i]);
    ve[cheese].push_back(dist);
    sort((ve[cheese]).begin(), (ve[cheese]).end());
    num[cheese] = 1;
    if (((int)(ve[cheese]).size()) >= 2 && ve[cheese][0] == ve[cheese][1])
      num[cheese] = 2;
  };
  for (int i : mice) {
    int d1 = delta(choice[i], i);
    int d2 = delta(choice[i] - 1, i);
    if (d1 > d2) {
      upd(choice[i], i);
    } else {
      upd(choice[i] - 1, i);
    }
  }
  int ans = n;
  for (int i = (0); i < (m); i++) ans -= num[i];
  cout << ans << endl;
}
