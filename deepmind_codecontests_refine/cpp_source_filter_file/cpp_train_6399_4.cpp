#include <bits/stdc++.h>
using namespace std;
struct road {
  float a;
  float b;
  float c;
};
int steps = 0;
int number;
road *ways = new road[320];
struct point {
  float x;
  float y;
};
point home;
point university;
float miny;
float maxy;
float minx;
float maxx;
bool crossing(int i) {
  if (ways[0].a != 0) {
    float y;
    float a2 = ways[i].a;
    float a1 = ways[0].a;
    float b1 = ways[0].b;
    float b2 = ways[i].b;
    float c1 = ways[0].c;
    float c2 = ways[i].c;
    float b = -a2 * b1 + a1 * b2;
    float c = a1 * c2 - a2 * c1;
    if (b != 0) {
      y = (float)(c * 1.0) / (b * 1.0);
      if (y - miny > 0.000001 && maxy - y > 0.000001)
        return true;
      else
        return false;
    } else
      return false;
  } else {
    float x;
    float a2 = ways[i].a;
    float a1 = ways[0].a;
    float b1 = ways[0].b;
    float b2 = ways[i].b;
    float c1 = ways[0].c;
    float c2 = ways[i].c;
    float b = -a2 * b1 + a1 * b2;
    float c = b1 * c2 - b2 * c1;
    if (b != 0) {
      x = (float)(c * 1.0) / (b * 1.0);
      if (x - minx > 0.00001 && maxx - x > 0.000001)
        return true;
      else
        return false;
    } else
      return false;
  }
}
int main() {
  cin >> home.x >> home.y;
  cin >> university.x >> university.y;
  cin >> number;
  for (int i = 1; i <= number; i++) {
    cin >> ways[i].a >> ways[i].b >> ways[i].c;
  }
  ways[0].a = university.y - home.y;
  ways[0].b = home.x - university.x;
  ways[0].c =
      home.x * (home.y - university.y) + home.y * (university.x - home.x);
  miny = min(university.y, home.y);
  maxy = max(university.y, home.y);
  minx = min(university.x, home.x);
  maxx = max(university.x, home.x);
  for (int i = 1; i <= number; i++) {
    if (crossing(i)) steps++;
  }
  cout << steps << "\n";
  return 0;
}
