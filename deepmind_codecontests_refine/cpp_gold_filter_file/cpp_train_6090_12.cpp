#include <bits/stdc++.h>
int t1, t2, t3, t4, t5;
int n;
int p0 = 0;
std::pair<int, int> p1[1000005];
int c0 = 0;
std::pair<int, int> c1[200005];
int c2 = 0;
std::pair<int, int> c3[100005];
long long a, b, c, d, e, f;
long long x, y, z;
double r;
int ans;
double bestr = -1;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d", &t1, &t2, &t3);
    if (t1 >= t3) {
      p1[p0++] = {t1 - t3, t2};
    } else {
      p1[p0++] = {0, (t2 - t3 + t1 >= 0 ? t2 - t3 + t1 : 0)};
      p1[p0++] = {0, (t2 + t3 - t1 <= 100000 ? t2 + t3 - t1 : 100000)};
    }
    if (t2 >= t3) {
      p1[p0++] = {t1, t2 - t3};
    } else {
      p1[p0++] = {(t1 - t3 + t2 >= 0 ? t1 - t3 + t2 : 0), 0};
      p1[p0++] = {(t1 + t3 - t2 <= 100000 ? t1 + t3 - t2 : 100000), 0};
    }
    if (t1 + t3 <= 100000) {
      p1[p0++] = {t1 + t3, t2};
    } else {
      p1[p0++] = {100000,
                  (t2 - t3 + 100000 - t1 >= 0 ? t2 - t3 + 100000 - t1 : 0)};
      p1[p0++] = {
          100000,
          (t2 + t3 - 100000 + t1 <= 100000 ? t2 + t3 - 100000 + t1 : 100000)};
    }
    if (t2 + t3 <= 100000) {
      p1[p0++] = {t1, t2 + t3};
    } else {
      p1[p0++] = {(t1 - t3 + 100000 - t2 >= 0 ? t1 - t3 + 100000 - t2 : 0),
                  100000};
      p1[p0++] = {
          (t1 + t3 - 100000 + t2 <= 100000 ? t1 + t3 - 100000 + t2 : 100000),
          100000};
    }
  }
  std::sort(p1, p1 + p0);
  for (int i = 0; i < p0; i++) {
    while (c0 >= 2) {
      t1 = c1[c0 - 1].first - c1[c0 - 2].first;
      t2 = c1[c0 - 1].second - c1[c0 - 2].second;
      t3 = c1[c0 - 1].first - p1[i].first;
      t4 = c1[c0 - 1].second - p1[i].second;
      if (t1 * (long long)t4 - t2 * (long long)t3 <= 0)
        c0--;
      else
        break;
    }
    c1[c0++] = p1[i];
    if (c2 && c3[c2 - 1].first == p1[i].first) continue;
    while (c2 >= 2) {
      t1 = c3[c2 - 1].first - c3[c2 - 2].first;
      t2 = c3[c2 - 1].second - c3[c2 - 2].second;
      t3 = c3[c2 - 1].first - p1[i].first;
      t4 = c3[c2 - 1].second - p1[i].second;
      if (t1 * (long long)t4 - t2 * (long long)t3 >= 0)
        c2--;
      else
        break;
    }
    c3[c2++] = p1[i];
  }
  if (c1[c0 - 1] == c3[c2 - 1]) c2--;
  while (c2--) {
    c1[c0++] = c3[c2];
  }
  if (c1[c0 - 1] == c1[0]) c0--;
  c1[c0] = c1[0];
  c1[c0 + 1] = c1[1];
  c1[c0 + 2] = c1[2];
  for (int i = 0; i < c0; i++) {
    a = 2 * c1[i].first - 2 * c1[i + 1].first;
    b = 2 * c1[i].second - 2 * c1[i + 1].second;
    c = (c1[i].first * (long long)c1[i].first) +
        (c1[i].second * (long long)c1[i].second) -
        (c1[i + 1].first * (long long)c1[i + 1].first) -
        (c1[i + 1].second * (long long)c1[i + 1].second);
    d = 2 * c1[i].first - 2 * c1[i + 2].first;
    e = 2 * c1[i].second - 2 * c1[i + 2].second;
    f = (c1[i].first * (long long)c1[i].first) +
        (c1[i].second * (long long)c1[i].second) -
        (c1[i + 2].first * (long long)c1[i + 2].first) -
        (c1[i + 2].second * (long long)c1[i + 2].second);
    x = c * e - b * f;
    y = a * f - c * d;
    z = a * e - b * d;
    a = c1[i].first;
    b = c1[i].second;
    r = ((a * z - x) * (double)(a * z - x) +
         (b * z - y) * (double)(b * z - y)) /
        z / z;
    if (bestr < r) {
      bestr = r;
      ans = i;
    }
  }
  for (int i = ans; i < ans + 3; i++)
    printf("%d %d\n", c1[i].first, c1[i].second);
}
