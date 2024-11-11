#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long fastpower(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return fastpower((x * x) % M, n / 2, M);
  else
    return (x * fastpower((x * x) % M, (n - 1) / 2, M)) % M;
}
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
long long modInverse(long long A, long long M) {
  return fastpower(A, M - 2, M);
}
void sieve(long long N) {
  bool isPrime[N + 1];
  for (long long i = 0; i <= N; ++i) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (long long i = 2; i * i <= N; ++i) {
    if (isPrime[i] == true) {
      for (long long j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
}
vector<long long> factorize(long long n) {
  vector<long long> res;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}
char ans[1005][1005];
pair<long long, long long> arr[1005][1005];
long long vis[1005][1005];
void dfs(long long a, long long b, long long x, long long y, long long n) {
  if (a == x && b == y) {
    ans[x][y] = 'X';
    vis[x][y] = 1;
  }
  long long p[] = {0, -1, 0, 1};
  long long q[] = {-1, 0, 1, 0};
  for (int i = 0; i < 4; i++) {
    long long c = (x + p[i]);
    long long d = (y + q[i]);
    if (c > 0 && (c <= n) && (d) <= n && d > 0 && !vis[c][d] &&
        arr[c][d].first == a && arr[c][d].second == b) {
      if (i == 0) {
        ans[c][d] = 'R';
        vis[c][d] = 1;
        dfs(a, b, c, d, n);
      } else if (i == 1) {
        ans[c][d] = 'D';
        vis[c][d] = 1;
        dfs(a, b, c, d, n);
      } else if (i == 2) {
        ans[c][d] = 'L';
        vis[c][d] = 1;
        dfs(a, b, c, d, n);
      } else if (i == 3) {
        ans[c][d] = 'U';
        vis[c][d] = 1;
        dfs(a, b, c, d, n);
      }
    }
  }
}
void df(long long a, long long b, long long c, long long d, char x, char y) {
  if (arr[c][d].first == -1) {
    ans[a][b] = x;
    if (!ans[c][d]) ans[c][d] = y;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      long long x, y;
      cin >> x >> y;
      arr[i][j] = {x, y};
    }
  }
  int flag = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (arr[i][j].first == i && arr[i][j].second == j) {
        dfs(i, j, i, j, n);
      } else if (arr[i][j].first == -1) {
        if (!ans[i][j]) {
          df(i, j, i + 1, j, 'D', 'U');
        }
        if (!ans[i][j]) {
          df(i, j, i, j + 1, 'R', 'L');
        }
        if (!ans[i][j]) {
          df(i, j, i - 1, j, 'U', 'D');
        }
        if (!ans[i][j]) {
          df(i, j, i, j - 1, 'L', 'R');
        }
        if (!ans[i][j]) flag = 1;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (!ans[i][j]) flag = 1;
    }
  }
  if (flag)
    cout << "INVALID" << endl;
  else {
    cout << "VALID" << endl;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
