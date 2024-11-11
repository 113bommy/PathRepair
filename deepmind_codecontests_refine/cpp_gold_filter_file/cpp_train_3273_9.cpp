#include <bits/stdc++.h>
using namespace std;
void online(void) {}
const long long N = 1299721;
vector<long long> prime(N, 1);
vector<long long> c;
void sieve(int N) {
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i <= sqrt(N); i++) {
    if (prime[i] == 1) {
      for (long long j = (i * i); j <= N; j += i) prime[j] = 0;
    }
  }
}
vector<long long> primeFactors;
void pFacotrs(long long x) {
  long long n = x;
  while (n % 2 == 0) {
    primeFactors.push_back(2);
    n /= 2;
  }
  long long n1 = sqrt(n);
  for (int i = 3; i <= n1; i += 2) {
    while (n % i == 0) {
      primeFactors.push_back(i);
      n /= i;
    }
  }
  if (n > 2) primeFactors.push_back(n);
}
void addEdge(long long u, long long v, vector<long long> g[]) {
  g[u].push_back(v);
}
long long DFSUtil(long long u, vector<long long> adj[], vector<bool> &visited) {
  visited[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    if (visited[adj[u][i]] == false) {
      DFSUtil(adj[u][i], adj, visited);
    }
  }
  return 0;
}
void DFS(vector<long long> adj[], int V) {
  vector<bool> visited(V + 1, false);
  vector<long long> v;
  for (int u = 1; u <= V; u++) {
    if (visited[u] == false) {
      v.push_back(DFSUtil(u, adj, visited));
    }
    fill(visited.begin(), visited.end(), false);
  }
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
int chk(int i, int j, vector<string> v, int r, int c) {
  if (i < 0 || j < 0 || i >= r || j >= c)
    return 0;
  else if (v[i][j] == 'W')
    return 1;
  return 0;
}
int main() {
  online();
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  while (T--) {
    long long n;
    cin >> n;
    long long home[n], away[n];
    for (int i = 0; i < n; i++) cin >> home[i] >> away[i];
    long long c[200005];
    fill(c + 1, c + n + 1, 0);
    for (int i = 0; i < n; i++) c[home[i]]++;
    long long ansHome[n], ansAway[n];
    fill(ansHome, ansHome + n, 0);
    fill(ansAway, ansAway + n, 0);
    for (int i = 0; i < n; i++) {
      ansHome[i] += n - 1;
      ansHome[i] += c[away[i]];
      ansAway[i] += 2 * (n - 1) - ansHome[i];
      cout << ansHome[i] << " " << ansAway[i] << endl;
    }
  }
  return 0;
}
