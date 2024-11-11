#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
vector<pair<long long, long long> > V;
vector<long long> ans;
struct TE {
  long long a, b;
} E[101000];
long long n, m, st[101000], sum;
bool cmp(TE a, TE b) {
  if (a.a == b.a) return a.b < b.b;
  return a.a < b.a;
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> E[i].a;
    st[i] = E[i].a;
    sum += E[i].a;
    E[i].b = i;
  }
  if (sum < m) {
    puts("-1");
    return 0;
  }
  if (sum == m) {
    puts("");
    puts("");
    return 0;
  }
  sort(E, E + n, cmp);
  long long res = n, now = 0;
  for (long long i = 0; i < n;)
    if ((E[i].a - now) * res >= m) {
      now += m / res;
      m -= m / res * res;
      for (long long j = 0; j < n; j++)
        if (st[j] > now) V.push_back(make_pair(st[j], j));
      for (long long j = m; j < V.size(); j++) ans.push_back(V[j].second);
      for (long long j = 0; j < m; j++)
        if (V[j].first > now + 1) ans.push_back(V[j].second);
      for (long long j = 0; j < ans.size(); j++)
        if (j == 0)
          printf("%I64d", ans[j] + 1);
        else
          printf(" %I64d", ans[j] + 1);
      puts("");
      break;
    } else {
      m -= (E[i].a - now) * res;
      long long nn = E[i].a;
      while (E[i].a == nn) {
        i++;
        res--;
      }
      now = nn;
    }
}
