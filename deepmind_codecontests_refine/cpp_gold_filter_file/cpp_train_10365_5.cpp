#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> g[201];
long long input[201];
long long output[201];
long long f(long long n) {
  fill(input, input + 201, 0);
  fill(output, output + 201, 0);
  for (long long i = 1; i <= n; i++) {
    for (auto [u, orr] : g[i]) {
      if (orr) {
        output[i]++;
        input[u]++;
      }
    }
  }
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    cnt += input[i] == output[i];
  }
  return cnt;
}
long long ok[201];
signed main() {
  long long t;
  cin >> t;
  for (long long _q = 0; _q < t; _q++) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      g[i].clear();
    }
    fill(ok, ok + 201, 0);
    for (long long i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      ok[a] = 1;
      ok[b] = 1;
      bool fl = rand() % 2;
      g[a].emplace_back(b, fl);
      g[b].emplace_back(a, !fl);
    }
    vector<long long> good;
    for (long long i = 1; i <= n; i++) {
      if (ok[i]) {
        good.push_back(i);
      }
      sort(g[i].begin(), g[i].end());
    }
    long long noww = f(n);
    long long ans = noww;
    long long pos = 0;
    long long now_i = 0;
    double t = 1;
    vector<pair<long long, pair<long long, long long>>> changes;
    for (long long _i = 0; _i < 2500 * n; _i++) {
      if (good.size() == 0) {
        break;
      }
      long long v = good[rand() % good.size()];
      long long poss = rand() % g[v].size();
      long long now = noww;
      if (input[v] == output[v]) {
        now--;
      }
      if (input[g[v][poss].first] == output[g[v][poss].first]) {
        now--;
      }
      if (g[v][poss].second) {
        if (input[v] + 2 == output[v]) {
          now++;
        }
        if (input[g[v][poss].first] - 2 == output[g[v][poss].first]) {
          now++;
        }
      } else {
        if (input[v] - 2 == output[v]) {
          now++;
        }
        if (input[g[v][poss].first] + 2 == output[g[v][poss].first]) {
          now++;
        }
      }
      if (now > noww || (double)rand() / RAND_MAX < exp((now - noww) / t)) {
        if (g[v][poss].second) {
          input[v] += 1;
          output[v] -= 1;
          output[g[v][poss].first] += 1;
          input[g[v][poss].first] -= 1;
        } else {
          input[v] -= 1;
          output[v] += 1;
          output[g[v][poss].first] -= 1;
          input[g[v][poss].first] += 1;
        }
        g[v][poss].second ^= 1;
        auto it =
            lower_bound(g[g[v][poss].first].begin(), g[g[v][poss].first].end(),
                        make_pair(v, g[v][poss].second));
        it->second ^= 1;
        noww = now;
        now_i++;
        changes.push_back({v, {poss, it - g[g[v][poss].first].begin()}});
      }
      if (now > ans) {
        ans = now;
        pos = now_i;
      }
      t *= 0.9999;
    }
    for (long long _i = 0; _i < changes.size() - pos; _i++) {
      long long real_i = changes.size() - _i - 1;
      g[changes[real_i].first][changes[real_i].second.first].second ^= 1;
      g[g[changes[real_i].first][changes[real_i].second.first].first]
       [changes[real_i].second.second]
           .second ^= 1;
    }
    cout << ans << endl;
    for (long long i = 1; i <= n; i++) {
      for (auto u : g[i]) {
        if (u.second) {
          cout << i << ' ' << u.first << endl;
        }
      }
    }
  }
}
