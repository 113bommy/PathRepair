#include <bits/stdc++.h>
using namespace std;
long double pi = acos(-1.);
void build(long i, long n) {
  if (i == 1) cout << 1 << " ";
  cout << 4 * i << " ";
  if (i != n) build(i + 1, n);
  if (i == 1)
    cout << "2 5 3 1 ";
  else {
    i--;
    cout << 4 * i + 2 << " " << 4 * i + 5 << " " << 4 * i + 3 << " " << 4 * i
         << " ";
  }
}
int main() {
  long n;
  cin >> n;
  long double x = -4900, y = -4900;
  cout << 4 * n + 1 << "\n";
  long double temp = 200 - 200 * cos(0.6 * pi);
  temp = sqrt(temp - 25);
  cout << fixed << setprecision(15) << x << " " << y << "\n";
  for (long i = 0; i < n; i++) {
    cout << fixed << setprecision(15) << x + 10 << " " << y << "\n";
    cout << fixed << setprecision(15) << x + 10 + 10 * cos(2 * pi / 5) << " "
         << y + 10 * sin(2 * pi / 5) << "\n";
    cout << fixed << setprecision(15) << x + 5 << " " << y + temp << "\n";
    cout << fixed << setprecision(15) << x - 10 * cos(2 * pi / 5) << " "
         << y + 10 * sin(2 * pi / 5) << "\n";
    x += 5;
    y += temp;
  }
  cout << "1 2 3 4 5\n";
  for (long i = 1; i < n; i++)
    cout << 4 * i << " " << 4 * i + 2 << " " << 4 * i + 3 << " " << 4 * i + 4
         << " " << 4 * i + 5 << "\n";
  build(1, n);
}
