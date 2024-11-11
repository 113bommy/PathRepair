#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double PI2 = 6.28318530717958;
const double PId2 = 1.570796326794895;
inline vector<int> ReadVI(int count) {
  vector<int> arrayname(count);
  for (int i = 0; i < int(count); i++) cin >> arrayname[i];
  return arrayname;
};
inline vector<pair<int, int> > ReadVII(int count) {
  vector<pair<int, int> > arrayname(count);
  for (int i = 0; i < int(count); i++) {
    cin >> arrayname[i].first;
    arrayname[i].second = i;
  }
  return arrayname;
};
const int MOD = 1000000007;
const int MAXVALUE = 100001;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  a[0] = 0;
  a[1] = 1;
  if (n == 1) return cout << 1, 0;
  for (int i = 2; i <= n; i++) {
    a[i] = 12 * (n - 1);
  }
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    sum += a[i];
  }
  cout << sum;
  return 0;
}
