#include <bits/stdc++.h>
using namespace std;
struct ple {
  vector<long double> v;
  int n;
  ple(int k) {
    n = k;
    v.resize(n + 1 + 1 + n + 1);
  }
  long double& operator[](int ind) { return v[n + 1 + ind]; }
};
const int N = 100 * 1000 + 3;
void myk(int pos, int n, int m, ple& act) {
  int k = n * m;
  ple mines(k + 1), plusos(k + 1);
  for (auto i = (-k - 1); i <= (k + 1); ++i) act[i] /= (long double)(m - 1);
  {
    int a = pos - 1;
    long double r1 = 0;
    for (auto i = (-k); i <= (-k + a - 1); ++i) r1 += act[i];
    for (auto i = (-k - 1); i <= (k); ++i) {
      mines[i] = r1;
      r1 -= act[i + 1];
      if (i + a + 1 <= k + 1)
        r1 += act[i + a + 1];
      else
        break;
    }
  }
  {
    int a = m - pos;
    long double r1 = 0;
    for (auto i = (-k - 1); i <= (-k + a - 2); ++i) r1 += act[i];
    for (auto i = (-k + a - 1); i <= (k); ++i) {
      plusos[i] = r1;
      r1 -= act[i - a];
      r1 += act[i];
    }
  }
  for (auto i = (-k - 1); i <= (k + 1); ++i) act[i] = mines[i] + plusos[i];
}
void jebaj() {
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << "1.0\n";
    return;
  }
  ple res(n * m);
  res[0] = 1;
  for (auto i = (0); i <= ((n)-1); ++i) {
    int a;
    cin >> a;
    myk(a, n, m, res);
  }
  long double wyn = 0;
  for (auto i = (-(n * m)); i <= (-1); ++i) wyn += (res[i]);
  cout << fixed << setprecision(10) << 1.0 + (m - 1) * wyn << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  int t = 1;
  for (auto i = (0); i <= ((t)-1); ++i) {
    jebaj();
  }
}
