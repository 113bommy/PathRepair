#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e8;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const int N = 100;
long long gcd(long long a, long long b) {
  for (;;) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
long long lcm(long long a, long long b) {
  int temp = gcd(a, b);
  return temp ? (a / temp * b) : 0;
}
int main() {
  ios::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double screen = (double)a / b;
  double movie = (double)c / d;
  if (screen < movie) {
    int heightScreen = b * c;
    int heightMovie = a * d;
    int divi = gcd(heightScreen, heightScreen - heightMovie);
    cout << (heightScreen - heightMovie) / divi << "/" << heightScreen / divi
         << endl;
  } else if (screen > movie) {
    int widthScreen = a * d;
    int widthMovie = c * b;
    int divi = gcd(widthScreen, (widthScreen - widthMovie));
    cout << (widthScreen - widthMovie) / divi << "/" << widthScreen / divi
         << endl;
  } else {
    cout << "0:1" << endl;
  }
  return 0;
}
