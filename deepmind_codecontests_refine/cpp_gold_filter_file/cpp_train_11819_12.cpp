#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long fact(long long n) {
  long long ret = 1;
  for (int i = 1; i <= n; i++) ret *= i;
  return ret;
}
bool is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  return 0;
}
long double getDistance(long double x1, long double y1, long double x2,
                        long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int n, b, q, upto[N], qu[N];
vector<pair<int, int> > v;
int main() {
  scanf("%d%d%d", &n, &b, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &upto[i], &qu[i]);
    v.push_back(pair<int, int>(upto[i], qu[i]));
  }
  sort(v.begin(), v.end());
  v.push_back(pair<int, int>(b, n));
  for (int i = 0; i < q; i++) {
    if (v[i].second > v[i + 1].second) {
      cout << "unfair";
      return 0;
    }
  }
  for (int i = 1; i < (1 << 5); i++) {
    int sum = 0;
    for (int j = 0; j < 5; j++) {
      if (i & (1 << j)) sum++;
    }
    sum *= (n / 5);
    int cur = 1, prev = 0;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].first < cur) continue;
      int matching = 0;
      while (cur <= v[j].first) {
        int rem = cur % 5;
        if (i & (1 << rem)) {
          matching++;
        }
        cur++;
      }
      sum -= min(matching, v[j].second - prev);
      prev = v[j].second;
    }
    if (sum > 0) {
      printf("unfair");
      return 0;
    }
  }
  printf("fair");
  return 0;
}
