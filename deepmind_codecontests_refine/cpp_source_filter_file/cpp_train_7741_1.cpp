#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 10;
int n, m, l[Maxn], ans1, ans2;
long double a, b;
pair<long double, int> arr[Maxn], brr[Maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> brr[i].first;
    brr[i].second = i;
  }
  for (int i = 0; i < m; i++) cin >> l[i];
  sort(arr, arr + n);
  sort(brr, brr + m);
  int cup;
  long double Min = LLONG_MAX;
  for (int i = 0; i < m; i++) {
    long double p = (brr[i].first * a) / b;
    int ind = lower_bound(arr, arr + n, make_pair(p, -1)) - arr;
    long double c, dis;
    if (ind < n) {
      c = arr[ind].first,
      dis = sqrt(a * a + c * c) +
            sqrt((b - a) * (b - a) + (brr[i].first - c) * (brr[i].first - c));
      cup = ind;
    }
    if (ind > 0) {
      ind--;
      c = arr[ind].first;
      if (sqrt(a * a + c * c) + sqrt((b - a) * (b - a) +
                                     (brr[i].first - c) * (brr[i].first - c)) <
          dis) {
        cup = ind;
        dis = sqrt(a * a + c * c) +
              sqrt((b - a) * (b - a) + (brr[i].first - c) * (brr[i].first - c));
      }
    }
    if (dis + l[arr[i].second] < Min) {
      Min = dis + l[arr[i].second];
      ans1 = arr[cup].second + 1, ans2 = brr[i].second + 1;
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
