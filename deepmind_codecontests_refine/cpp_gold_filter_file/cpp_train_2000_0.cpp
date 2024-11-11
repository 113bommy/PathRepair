#include <bits/stdc++.h>
long long a[4], b[4];
long long gcd(long long x, long long y) {
  long long r;
  while (y) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}
std::vector<std::pair<long long, long long> > F(std::vector<long long> a) {
  std::vector<std::pair<long long, long long> > result;
  while (a[0] < 0 || a[3] > 1) {
    bool ok = false;
    for (int i = 0; i < 3; i++)
      if ((a[3] - a[i]) * 3 >= a[i] && a[i] * 2 - a[3] >= 0) {
        result.push_back({a[3], a[i]});
        a[3] = a[i] * 2 - a[3];
        std::sort(a.begin(), a.end());
        ok = true;
        break;
      }
    if (ok) continue;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++)
        if ((a[j] - a[i]) * 2 <= a[3] && (a[j] - a[i]) * 6 >= a[3]) {
          result.push_back({a[3], a[j]});
          result.push_back({a[j] * 2 - a[3], a[i]});
          a[3] -= (a[j] - a[i]) * 2;
          std::sort(a.begin(), a.end());
          ok = true;
          break;
        }
      if (ok) break;
    }
    if (ok) continue;
    if (a[0] * 2 > a[3]) {
      result.push_back({a[3], a[0]});
      a[3] = a[0] * 2 - a[3];
      std::sort(a.begin(), a.end());
      continue;
    }
    if (a[1] * 2 > a[3]) {
      result.push_back({a[3], a[1]});
      a[3] = a[1] * 2 - a[3];
      std::sort(a.begin(), a.end());
      continue;
    }
    if (a[2] * 2 > a[3]) {
      if (a[1] - a[0] > a[3] - a[2]) {
        result.push_back({a[2], a[1]});
        result.push_back({a[1] * 2 - a[2], a[0]});
        a[2] -= (a[1] - a[0]) * 2;
        std::sort(a.begin(), a.end());
        continue;
      } else {
        result.push_back({a[1], a[2]});
        result.push_back({a[2] * 2 - a[1], a[3]});
        a[1] += (a[3] - a[2]) * 2;
        std::sort(a.begin(), a.end());
        continue;
      }
    }
    result.push_back({a[0], a[2]});
    a[0] = a[2] * 2 - a[0];
    std::sort(a.begin(), a.end());
  }
  return result;
}
int main() {
  for (int i = 0; i < 4; i++) scanf("%lld", a + i);
  for (int i = 0; i < 4; i++) scanf("%lld", b + i);
  std::sort(a, a + 4);
  std::sort(b, b + 4);
  if (a[0] == a[3]) {
    if (b[0] != a[0] || b[3] != a[3])
      puts("-1");
    else
      puts("0");
    return 0;
  }
  if (b[0] == b[3]) {
    puts("-1");
    return 0;
  }
  long long ga = gcd(gcd(a[1] - a[0], a[2] - a[0]), a[3] - a[0]);
  long long gb = gcd(gcd(b[1] - b[0], b[2] - b[0]), b[3] - b[0]);
  long long ra = (a[0] % ga + ga) % ga;
  long long rb = (b[0] % gb + gb) % gb;
  if (ga != gb || ra != rb) {
    puts("-1");
    return 0;
  }
  ra = std::min(a[0], b[0]);
  for (int i = 0; i < 4; i++) a[i] = (a[i] - ra) / ga;
  for (int i = 0; i < 4; i++) b[i] = (b[i] - ra) / ga;
  int odda = 0, oddb = 0;
  for (int i = 0; i < 4; i++) odda += a[i] & 1;
  for (int i = 0; i < 4; i++) oddb += b[i] & 1;
  if (odda != oddb) {
    puts("-1");
    return 0;
  }
  std::vector<std::pair<long long, long long> > va = F({a, a + 4}),
                                                vb = F({b, b + 4});
  printf("%d\n", int(va.size()) + int(vb.size()));
  for (auto i = va.begin(); i != va.end(); i++)
    printf("%lld %lld\n", i->first * ga + ra, i->second * ga + ra);
  for (auto i = vb.rbegin(); i != vb.rend(); i++)
    printf("%lld %lld\n", (i->second * 2 - i->first) * ga + ra,
           i->second * ga + ra);
  return 0;
}
