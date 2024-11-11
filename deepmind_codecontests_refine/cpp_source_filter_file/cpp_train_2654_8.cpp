#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if ((a == 0) || (b == 0)) return a + b;
  return gcd(b, a % b);
}
long long pow_mod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
vector<int> adj[100010];
long long col[100010], visited[100010], arr[100010];
long long c0, c1, cnt;
void dfs(long long src, long long par) {
  visited[src] = 1;
  long long h = adj[src].size(), i, xx;
  cnt++;
  for (i = 0; i <= h - 1; i++) {
    xx = adj[src][i];
    if ((xx == par) || (visited[xx] == 1)) {
      continue;
    }
    dfs(xx, src);
  }
}
long long comb3(long long N) { return (N * (N - 1) * (N - 2)) / 6; }
long long comb2(long long N) { return (N * (N - 1)) / 2; }
bool bipartile(long long src) {
  long long uu = 0, i, h, xx;
  queue<long long> qu;
  col[src] = 1;
  qu.push(src);
  c1++;
  while (!qu.empty()) {
    uu = qu.front();
    qu.pop();
    h = adj[uu].size();
    for (i = 0; i <= h - 1; i++) {
      xx = adj[uu][i];
      if (col[xx] == -1) {
        col[xx] = 1 - col[uu];
        qu.push(xx);
        if (col[xx] == 1) {
          c1++;
        } else {
          c0++;
        }
      } else if (col[xx] == col[uu]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long N, i, j, A, B, maxx = -9223372036854775807, M;
  string st;
  cin >> N >> M;
  for (i = 0; i <= M - 1; i++) {
    cin >> A >> B;
    --A;
    --B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  memset(col, -1, sizeof(col));
  for (i = 0; i <= N - 1; i++) {
    if (col[i] == -1) {
      if (bipartile(i) != 1) {
        cout << "0 1";
        return 0;
      }
    }
  }
  for (i = 0; i <= N - 1; i++) {
    if (visited[i] == 0) {
      cnt = 0;
      dfs(i, -1);
      maxx = ((maxx) > (cnt) ? (maxx) : (cnt));
      arr[cnt]++;
    }
  }
  if (maxx == 1) {
    cout << "3 ";
    cout << comb3(N);
    return 0;
  } else if (maxx == 2) {
    cout << "2 ";
    long long ans = (comb2(arr[2]) * 4) + (arr[2] * (N - arr[2]));
    cout << ans;
    return 0;
  } else {
    long long ans = 0;
    cout << "1 ";
    memset(col, -1, sizeof(col));
    for (i = 0; i <= N - 1; i++) {
      if (col[i] == -1) {
        c0 = 0;
        c1 = 0;
        bipartile(i);
        ans += comb2(c0) + comb2(c1);
      }
    }
    cout << ans;
  }
  return 0;
}
