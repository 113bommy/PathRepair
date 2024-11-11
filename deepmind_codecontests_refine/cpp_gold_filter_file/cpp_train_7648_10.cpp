#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 9, MOD = 1e9 + 7;
using vi = vector<long long>;
using vb = vector<bool>;
using vp = vector<pair<long long, long long>>;
mt19937 Flash_new_51(525252);
double vk_soset[N], vk_soset_yandex_top[N];
long long a[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  double c, mean = 0, T;
  cin >> n >> T >> c;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mean = (mean + double(a[i]) / T) / c;
    vk_soset[i] = mean;
    if (i) a[i] += a[i - 1];
    vk_soset_yandex_top[i] = (a[i] - (i + 1 > T) * (a[i - (long long)T])) / T;
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    long long o;
    cin >> o;
    o--;
    cout << setprecision(5) << fixed << vk_soset_yandex_top[o] << ' '
         << vk_soset[o] << ' '
         << double(abs(vk_soset[o] - vk_soset_yandex_top[o])) /
                vk_soset_yandex_top[o]
         << "\n";
  }
}
