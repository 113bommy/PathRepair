#include <bits/stdc++.h>
const int N = 1e5 + 5, MM = N * 2;
int n, M;
int adj[N], v[MM], nxt[MM], digit[MM], e;
bool cut[N];
__inline void ins(int u0, int v0, int d0) {
  v[e] = v0;
  nxt[e] = adj[u0];
  digit[e] = d0;
  cut[e] = false;
  adj[u0] = e++;
}
std::pair<int, std::pair<int, int>> expand_front(
    const std::pair<int, std::pair<int, int>>& line, int d) {
  std::pair<int, std::pair<int, int>> expanded = std::make_pair(
      (line.first * 10LL + d) % M,
      std::make_pair((line.second.first + 1LL * d * line.second.second) % M,
                     line.second.second * 10LL % M));
  return expanded;
}
std::pair<int, std::pair<int, int>> expand_back(
    const std::pair<int, std::pair<int, int>>& line, int d) {
  std::pair<int, std::pair<int, int>> expanded =
      std::make_pair((line.first + 1LL * d * line.second.second) % M,
                     std::make_pair((line.second.first * 10LL + d) % M,
                                    line.second.second * 10LL % M));
  return expanded;
}
int size[N];
void dfs(int u, int p, std::pair<int, std::pair<int, int>> cur,
         std::vector<std::pair<int, std::pair<int, int>>>& storage) {
  storage.push_back(cur);
  size[u] = 1;
  for (int e = adj[u]; ~e; e = nxt[e])
    if (!cut[e] && v[e] != p) {
      dfs(v[e], u, expand_back(cur, digit[e]), storage);
      size[u] += size[v[e]];
    }
}
long long ans = 0;
void ex_gcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  long long xx, yy;
  ex_gcd(b, a % b, xx, yy);
  y = xx - a / b * yy;
  x = yy;
}
long long inv(long long x, long long MODN) {
  long long inv_x, y;
  ex_gcd(x, MODN, inv_x, y);
  return (inv_x % MODN + MODN) % MODN;
}
std::vector<std::pair<int, std::pair<int, int>>> divide(int root) {
  std::vector<std::pair<int, std::pair<int, int>>> ret;
  dfs(root, -1, std::make_pair(0, std::make_pair(0, 1)), ret);
  int tot_size = size[root], center;
  if (tot_size == 1) return ret;
  for (int u = root;;) {
    int max_son = -1;
    for (int e = adj[u]; ~e; e = nxt[e])
      if (!cut[e] && size[v[e]] < size[u] &&
          (!~max_son || size[v[e]] > size[max_son])) {
        max_son = v[e];
      }
    if (size[max_son] * 2 <= tot_size) {
      center = u;
      break;
    } else {
      u = max_son;
    }
  }
  std::vector<std::pair<int, std::vector<std::pair<int, std::pair<int, int>>>>>
      sub_s;
  for (int e = adj[center]; ~e; e = nxt[e])
    if (!cut[e]) {
      cut[e] = cut[e ^ 1] = true;
      sub_s.push_back(std::make_pair(digit[e], divide(v[e])));
    }
  long long ans0 = ans;
  std::unordered_map<int, int> hash_front, hash_back;
  hash_front[0] = hash_back[0] = 1;
  for (const auto& storage : sub_s) {
    int d = storage.first;
    for (const std::pair<int, std::pair<int, int>>& line : storage.second) {
      std::pair<int, std::pair<int, int>> expanded = expand_front(line, d);
      ans += hash_front[1LL * (M - expanded.second.first) *
                        inv(expanded.second.second, M) % M] +
             hash_back[expanded.first];
      ans0 = ans;
    }
    for (const std::pair<int, std::pair<int, int>>& line : storage.second) {
      std::pair<int, std::pair<int, int>> expanded = expand_front(line, d);
      ++hash_front[expanded.first];
      ++hash_back[1LL * (M - expanded.second.first) *
                  inv(expanded.second.second, M) % M];
    }
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> M;
  memset(adj, -1, sizeof(*adj) * n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, d;
    std::cin >> u >> v >> d;
    ins(u, v, d);
    ins(v, u, d);
  }
  divide(0);
  std::cout << ans << std::endl;
}
