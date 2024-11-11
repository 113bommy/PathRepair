#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long mod) {
  long long c = 1;
  while (b > 0) {
    if (b % 2) c *= a, c %= mod;
    b /= 2;
    a *= a;
    a %= mod;
  }
  return c;
}
struct dt {
  long long i, c;
};
bool comp(dt a, dt b) { return a.c < b.c; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, MSK;
  MSK = 1 << 9;
  cin >> n >> m;
  vector<long long> v, p, ing;
  unordered_map<long long, vector<dt>> exist;
  unordered_map<long long, long long> satisfy;
  for (long long i = 0; i < n; i++) {
    long long f;
    cin >> f;
    long long num = 0;
    for (long long i = 0; i < f; i++) {
      long long a;
      cin >> a;
      a--;
      num = num | (1 << a);
    }
    satisfy[num]++;
  }
  for (long long i = 0; i < m; i++) {
    long long cost;
    cin >> cost;
    p.push_back(cost);
    long long r, num = 0;
    cin >> r;
    while (r--) {
      long long a;
      cin >> a;
      a--;
      num = num | (1 << a);
    }
    exist[num].push_back({i, cost});
  }
  for (long long i = 0; i < MSK; i++) {
    sort(exist[i].begin(), exist[i].end(), comp);
    while (exist[i].size() > 2) exist[i].pop_back();
  }
  long long req = 0, ans = 0, cost = 1000000007, ii = -1, jj = -1;
  for (long long i = 0; i < MSK; i++) {
    for (long long j = 0; j < MSK; j++) {
      if ((i == j) && (exist[i].size() < 2)) continue;
      if (exist[i].size() && exist[j].size()) {
        long long num = i | j;
        long long curans = 0, curcost = 0, p1, p2;
        curcost = exist[i][0].c;
        p1 = exist[i][0].i;
        if (i == j)
          curcost += exist[i][1].c, p2 = exist[i][1].i;
        else
          curcost += exist[j][0].c, p2 = exist[j][0].i;
        for (long long k = 0; k < MSK; k++) {
          if ((k & num) == k) curans += satisfy[k];
        }
        if (ans < curans) {
          ans = curans;
          cost = curcost;
          ii = p1, jj = p2;
        } else if (ans == curans && curcost < cost) {
          cost = curcost;
          ii = p1;
          jj = p2;
        }
      } else
        continue;
    }
  }
  cout << ii + 1 << " " << jj + 1 << "\n";
}
