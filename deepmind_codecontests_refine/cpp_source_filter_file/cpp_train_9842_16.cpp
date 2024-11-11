#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 10;
long long arr[MN];
long long sum[MN];
int main() {
  double PI = acos(-1);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  {
    int d, h, v, e;
    cin >> d >> h >> v >> e;
    double area = PI * d * d / 4.0;
    double V = 1.0 / area - e;
    if (V <= 0)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << fixed << setprecision(6);
      cout << (double)h / V << "\n";
    }
  }
  return 0;
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  sort(arr + 1, arr + 1 + N);
  for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + arr[i];
  long long sol = 1e9 + 1000;
  for (int i = 1; i < N; i++) {
    sol = min(sol, abs(sum[i] - (sum[N] - sum[i])));
  }
  cout << sol + 1 << "\n";
  return 0;
}
