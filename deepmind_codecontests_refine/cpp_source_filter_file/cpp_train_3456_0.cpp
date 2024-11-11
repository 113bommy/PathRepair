#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<vector<long long>> a(n);
    for (int i = 0; i < n; i++) {
      int m;
      long long p;
      scanf("%d", &m);
      scanf("%lld", &p);
      a[m].push_back(p);
    }
    vector<int> cnt(n);
    cnt[0] = a[0].size();
    for (int i = 1; i < n; i++) {
      cnt[i] = cnt[i - 1] + a[i].size();
    }
    long long res = 0;
    multiset<long long> s;
    int ch = 0;
    for (int i = n - 1; i > 0; i--) {
      for (long long j : a[i]) s.insert(j);
      int temp = 0;
      for (int j = 0; j < i - ch - cnt[i - 1]; j++) {
        long long p = *(s.begin());
        s.erase(p);
        res += p;
        temp++;
      }
      ch += temp;
    }
    printf("%lld\n", res);
  }
}
