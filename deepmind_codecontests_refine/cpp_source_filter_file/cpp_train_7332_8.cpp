#include <bits/stdc++.h>
using namespace std;
struct city {
  int x, y, n;
  double r;
};
bool cmp(city c1, city c2) { return c1.r < c2.r; };
int main() {
  const int t = 1000;
  int n, m;
  city mas[t];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mas[i].x >> mas[i].y >> mas[i].n;
    mas[i].r = sqrt(pow(mas[i].x * 1.0, 2) + pow(mas[i].y * 1.0, 2));
  }
  sort(mas, mas + n, cmp);
  int i = -1;
  while (m < 1000000 && i < n) {
    i++;
    m += mas[i].n;
  }
  if (m < t)
    cout << -1;
  else
    cout << fixed << setprecision(7) << mas[i].r;
  return 0;
}
