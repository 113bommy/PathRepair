#include <bits/stdc++.h>
using namespace std;
const long long MAGIC = 888;
struct point {
  long long x, y, z;
  point() {}
  point(long long val) { x = y = z = val; }
};
vector<point> arr;
struct equation {
  pair<long long, long long> S;
  pair<long long, long long> a;
  pair<long long, long long> b;
  pair<long long, long long> c;
  equation() {}
  equation(long long f, long long s) {
    S.first = a.first = b.first = c.first = f;
    S.second = b.second = c.second = a.second = s;
  }
};
equation calcCur(long long mid) {
  equation cur = equation(-9e18, 9e18);
  for (int i = 0; i < arr.size(); i++) {
    equation item;
    item.S.first = arr[i].x + arr[i].y + arr[i].z - mid;
    item.S.second = arr[i].x + arr[i].y + arr[i].z + mid;
    item.a.first = -arr[i].x + arr[i].y + arr[i].z - mid;
    item.a.second = -arr[i].x + arr[i].y + arr[i].z + mid;
    item.b.first = arr[i].x - arr[i].y + arr[i].z - mid;
    item.b.second = arr[i].x - arr[i].y + arr[i].z + mid;
    item.c.first = arr[i].x + arr[i].y - arr[i].z - mid;
    item.c.second = arr[i].x + arr[i].y - arr[i].z + mid;
    cur.S.first = max(cur.S.first, item.S.first);
    cur.S.second = min(cur.S.second, item.S.second);
    cur.a.first = max(cur.a.first, item.a.first);
    cur.a.second = min(cur.a.second, item.a.second);
    cur.b.first = max(cur.b.first, item.b.first);
    cur.b.second = min(cur.b.second, item.b.second);
    cur.c.first = max(cur.c.first, item.c.first);
    cur.c.second = min(cur.c.second, item.c.second);
  }
  return cur;
}
point getSolution(equation cur) {
  if (cur.S.first > cur.S.second || cur.a.first > cur.a.second ||
      cur.b.first > cur.b.second || cur.c.first > cur.c.second ||
      cur.a.second + cur.b.second + cur.c.second < cur.S.first ||
      cur.a.first + cur.b.first + cur.c.first > cur.S.second) {
    return point(MAGIC);
  }
  point result;
  result.x = cur.a.first;
  result.y = cur.b.first;
  result.z = cur.c.first;
  long long delta = max(0ll, cur.S.first - result.x - result.y - result.z);
  result.x += min(cur.a.second - cur.a.first, delta);
  delta -= min(cur.a.second - cur.a.first, delta);
  result.y += min(cur.b.second - cur.b.first, delta);
  delta -= min(cur.b.second - cur.b.first, delta);
  result.z += min(cur.c.second - cur.c.first, delta);
  delta -= min(cur.c.second - cur.c.first, delta);
  assert(delta == 0);
  return result;
}
long long div2(long long x) { return (x - (x & 1)) / 2; }
point can(long long mid) {
  equation cur = calcCur(mid);
  for (int r = 0; r <= 1; r++) {
    equation final;
    final.S.first = div2(cur.S.first - 3 * r + 1);
    final.a.first = div2(cur.a.first - r + 1);
    final.b.first = div2(cur.b.first - r + 1);
    final.c.first = div2(cur.c.first - r + 1);
    final.S.second = div2(cur.S.second - 3 * r);
    final.a.second = div2(cur.a.second - r);
    final.b.second = div2(cur.b.second - r);
    final.c.second = div2(cur.c.second - r);
    point result = getSolution(final);
    if (result.x != MAGIC) {
      point answer;
      answer.x = result.y + result.z + r;
      answer.y = result.x + result.z + r;
      answer.z = result.x + result.y + r;
      return answer;
    }
  }
  return point(MAGIC);
}
void solve() {
  int n;
  cin >> n;
  arr.clear();
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d%I64d", &arr[i].x, &arr[i].y, &arr[i].z);
  }
  long long lf = -1;
  long long rg = 3e18 + 20;
  while (rg - lf > 1) {
    long long middle = lf + (rg - lf) / 2;
    if (can(middle).x != MAGIC) {
      rg = middle;
    } else {
      lf = middle;
    }
  }
  point answer;
  for (long long i = lf; i <= rg; i++) {
    if (can(i).x != MAGIC) {
      answer = can(i);
      cout << answer.x << " " << answer.y << " " << answer.z << endl;
      return;
    }
  }
  int s = -4;
  cout << arr[s].x << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
