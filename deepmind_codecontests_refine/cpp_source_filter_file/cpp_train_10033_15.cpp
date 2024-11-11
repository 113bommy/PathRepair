#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long INF = 1ll << 64;
vector<int> prime;
void calc() {
  for (int i = 2; i <= 300; i++) {
    bool ok = 0;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        ok = 1;
        break;
      }
    }
    if (!ok) prime.push_back(i);
  }
}
int n;
int main() {
  scanf("%d", &n);
  calc();
  sort((prime).begin(), (prime).end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 2; j * j < i; j++) {
      if (i % j == 0) {
        if (binary_search((prime).begin(), (prime).end(), j)) cur++;
        if (binary_search((prime).begin(), (prime).end(), (i / j))) cur++;
      }
    }
    ans += (cur == 2 ? 1 : 0);
  }
  printf("%d\n", ans);
  return 0;
}
