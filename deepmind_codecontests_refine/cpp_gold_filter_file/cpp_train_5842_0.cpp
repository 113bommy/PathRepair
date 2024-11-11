#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, int> M;
int n;
long long num;
vector<pair<int, long long> > edge[1000005];
long long rui[1000005];
void dfs(int v, long long r) {
  rui[v] = r;
  for (int i = 0; i < edge[v].size(); i++) {
    int to = edge[v][i].first;
    long long rr = (r ^ edge[v][i].second);
    dfs(to, rr);
  }
}
pair<int, int> my[10000005], you[10000005];
int nxt = 1;
int main() {
  scanf("%d%lld", &n, &num);
  for (int i = 1; i < n; i++) {
    int a;
    long long b;
    scanf("%d%lld", &a, &b);
    edge[a].push_back(make_pair(i + 1, b));
  }
  dfs(1, 0);
  long long ans = 0;
  sort(rui + 1, rui + n + 1);
  my[nxt] = make_pair(1, n);
  you[nxt++] = make_pair(1, n);
  for (int x = 61; x >= 0; x--) {
    long long N = 0;
    for (int i = 1; i < nxt; i++) {
      if (you[i].first > you[i].second) continue;
      long long a0 = 0, a1 = 0;
      long long b0 = 0, b1 = 0;
      for (int xx = my[i].first; xx <= my[i].second; xx++) {
        long long v = rui[xx];
        if (((v >> x) & 1LL)) {
          a1 = my[i].second - my[i].first + 1 - a0;
          break;
        } else
          a0++;
      }
      for (int xx = you[i].first; xx <= you[i].second; xx++) {
        long long v = rui[xx];
        if (((v >> x) & 1LL)) {
          b1 = you[i].second - you[i].first + 1 - b0;
          break;
        } else
          b0++;
      }
      N += (a0 * b0 + a1 * b1);
    }
    if (N >= num) {
      int prenxt = nxt;
      for (int i = 1; i < prenxt; i++) {
        if (you[i].first > you[i].second) continue;
        long long a0 = 0, a1 = 0;
        long long b0 = 0, b1 = 0;
        for (int xx = my[i].first; xx <= my[i].second; xx++) {
          long long v = rui[xx];
          if (((v >> x) & 1LL)) {
            a1 = my[i].second - my[i].first + 1 - a0;
            break;
          } else
            a0++;
        }
        for (int xx = you[i].first; xx <= you[i].second; xx++) {
          long long v = rui[xx];
          if (((v >> x) & 1LL)) {
            b1 = you[i].second - you[i].first + 1 - b0;
            break;
          } else
            b0++;
        }
        if (a0) {
          my[i].second = my[i].first + a0 - 1;
          you[i].second = you[i].first + b0 - 1;
          if (a1) {
            my[nxt] = make_pair(my[i].second + 1, my[i].second + a1);
            you[nxt++] = make_pair(you[i].second + 1, you[i].second + b1);
          }
        } else {
          you[i].first = you[i].second - b1 + 1;
        }
      }
    } else {
      num -= N;
      ans += (1LL << x);
      int prenxt = nxt;
      for (int i = 1; i < prenxt; i++) {
        if (you[i].first > you[i].second) continue;
        long long a0 = 0, a1 = 0;
        long long b0 = 0, b1 = 0;
        for (int xx = my[i].first; xx <= my[i].second; xx++) {
          long long v = rui[xx];
          if (((v >> x) & 1LL)) {
            a1 = my[i].second - my[i].first + 1 - a0;
            break;
          } else
            a0++;
        }
        for (int xx = you[i].first; xx <= you[i].second; xx++) {
          long long v = rui[xx];
          if (((v >> x) & 1LL)) {
            b1 = you[i].second - you[i].first + 1 - b0;
            break;
          } else
            b0++;
        }
        if (a0) {
          my[i].second = my[i].first + a0 - 1;
          you[i].first = you[i].second - b1 + 1;
          if (a1) {
            my[nxt] = make_pair(my[i].second + 1, my[i].second + a1);
            you[nxt++] = make_pair(you[i].first - b0, you[i].first - 1);
          }
        } else {
          you[i].second = you[i].first + b0 - 1;
        }
      }
    }
  }
  cout << ans << endl;
}
