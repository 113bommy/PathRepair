#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:99999999")
using namespace std;
long prime[1000001] = {0};
struct dot {
  double x;
  double y;
};
int main() {
  ios_base::sync_with_stdio(0);
  vector<dot> dots;
  dot myD;
  int n;
  cin >> n;
  double x;
  double r;
  cin >> r;
  cin >> x;
  myD.x = x;
  myD.y = r;
  dots.push_back(myD);
  for (int i = 1; i < n; ++i) {
    cin >> x;
    list<dot> variants;
    for (auto a : dots) {
      if (abs(a.x - x) <= 2 * r) variants.push_back(a);
    }
    myD.x = x;
    list<dot> results;
    for (auto a : variants) {
      myD.y = a.y + sqrt(4 * r * r - (a.x - x) * (a.x - x));
      results.push_back(myD);
    }
    double minY = 0;
    for (auto a : results)
      if (a.y > minY) minY = a.y;
    myD.y = minY;
    dots.push_back(myD);
  }
  cout << fixed << setprecision(10);
  for (auto a : dots) cout << a.y << " ";
  return 0;
}
