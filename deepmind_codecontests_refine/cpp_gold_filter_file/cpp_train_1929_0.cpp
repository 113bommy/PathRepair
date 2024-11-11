#include <bits/stdc++.h>
using namespace std;
int main() {
  long long px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  double first = px + (b * vx) / sqrt(vx * vx + vy * vy);
  double second = py + (b * vy) / sqrt(vx * vx + vy * vy);
  printf("%.13lf %.13lf\n", first, second);
  double ttvx = px + (vx), ttvy = py + vy;
  double tvx = px - ttvy + py, tvy = py - px + ttvx;
  tvx -= px;
  tvy -= py;
  first = px + ((a / 2.0) * tvx) / sqrt(tvx * tvx + tvy * tvy);
  second = py + ((a / 2.0) * tvy) / sqrt(tvx * tvx + tvy * tvy);
  printf("%.13lf %.13lf\n", first, second);
  first = px + (((c) / 2.0) * tvx) / sqrt(tvx * tvx + tvy * tvy);
  second = py + (((c) / 2.0) * tvy) / sqrt(tvx * tvx + tvy * tvy);
  printf("%.13lf %.13lf\n", first, second);
  first = first - (d * vx) / sqrt(vx * vx + vy * vy);
  second = second - (d * vy) / sqrt(vx * vx + vy * vy);
  printf("%.13lf %.13lf\n", first, second);
  first = first - (c * tvx) / sqrt(tvx * tvx + tvy * tvy);
  second = second - (c * tvy) / sqrt(tvx * tvx + tvy * tvy);
  printf("%.13lf %.13lf\n", first, second);
  first += (d * vx) / sqrt(vx * vx + vy * vy);
  second += (d * vy) / sqrt(vx * vx + vy * vy);
  printf("%.13lf %.13lf\n", first, second);
  first -= (((a - c) / 2.0) * tvx) / sqrt(tvx * tvx + tvy * tvy);
  second -= (((a - c) / 2.0) * tvy) / sqrt(tvx * tvx + tvy * tvy);
  printf("%.13lf %.13lf\n", first, second);
}
