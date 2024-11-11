#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
int main() {
  long long n;
  scanf("%I64d", &n);
  for (long long i = 1; i <= 200000; i++) {
    long long b = i * (i + 1) * (2 * i + 1) / 6;
    if (b > n)
      break;
    else if (b == n)
      v.push_back({i, i});
    else {
      if ((n - b) % (i * (i + 1) / 2) == 0) {
        v.push_back({i, (n - b) / (i * (i + 1) / 2) + i});
        v.push_back({(n - b) / (i * (i + 1) / 2) + i, i});
      }
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++)
    printf("%I64d %I64d\n", v[i].first, v[i].second);
}
