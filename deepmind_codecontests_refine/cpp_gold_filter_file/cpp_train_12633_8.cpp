#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
using namespace std;
const long double EPS = 1e-11;
const int INF = 2000000000;
const long long lINF = 9223372036854775807;
const long double PI = 3.14159265358979323846;
int main() {
  int n, i, k, m;
  const long double y1 = 10 * sin(PI / 5), x1 = 10 * cos(PI / 5),
                    y2 = 10 * cos(PI / 10), x2 = 10 * sin(PI / 10);
  cin >> n;
  cout << 4 * n + 1 << "\n";
  cout << 0 << ' ' << 0 << "\n";
  for (i = 2; i <= 4 * n + 1; i++) {
    k = (i - 2) / 4;
    m = i % 4;
    if (m == 0)
      printf("%.10lf %.10lf", 2 * x1 * (long double)(k + 1) - x2, -y2);
    if (m == 1) printf("%.10lf %.10lf", 2 * x1 * (long double)(k + 1), 0);
    if (m == 2) printf("%.10lf %.10lf", x2 + 2 * x1 * (long double)k, -y2);
    if (m == 3) printf("%.10lf %.10lf", x1 + 2 * x1 * (long double)k, y1);
    cout << "\n";
  }
  for (i = 0; i < n; i++)
    cout << i * 4 + 1 << ' ' << i * 4 + 3 << ' ' << i * 4 + 5 << ' '
         << i * 4 + 4 << ' ' << i * 4 + 2 << "\n";
  cout << 1 << ' ';
  for (i = 1; i <= n; i++) cout << 4 * i + 1 << ' ';
  for (i = n - 1; i >= 0; i--)
    cout << 4 * i + 2 << ' ' << 4 * i + 3 << ' ' << 4 * i + 4 << ' '
         << 4 * i + 1 << ' ';
  return 0;
}
