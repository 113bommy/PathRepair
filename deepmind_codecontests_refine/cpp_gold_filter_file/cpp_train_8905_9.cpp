#include <bits/stdc++.h>
using namespace std;
long long mInv[41];
long long fact[41];
long long factInv[41];
vector<pair<long, long> > edges;
map<string, long> cityId;
vector<pair<long, long> > criticalEdges;
vector<long> chlds[15];
vector<long> graph[200005];
long long heights[5];
long long segTree[3];
long nums[5005];
long g[5005];
long grid[15][15];
long base = 1005;
vector<long long> primes;
vector<long> badPrimes;
long funcVal[1];
long dfs_num[29], dfs_low[29], visited[29], parent[200009], criticalNode[19];
long bff[1100];
long inq[1010];
long source;
long long N;
set<string> dictionary;
pair<set<string>::iterator, bool> ret;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long getmoduloInv(long long n) {
  if (n == 1) return 1;
  if (mInv[n] > 0) return mInv[n];
  long long m = (-1 * 1000000007) / n;
  m += 1000000007;
  m *= getmoduloInv(1000000007 % n);
  mInv[n] = (m % 1000000007);
  return mInv[n];
}
vector<long long> get_primes(unsigned long maxN) {
  char *sieve;
  sieve = new char[maxN / 8 + 1];
  long m = (maxN / 8) + 1;
  for (long long i = 0; i < m; i++) sieve[i] = 255;
  for (unsigned long x = 2; x <= maxN; x++)
    if (sieve[x / 8] & (0x01 << (x % 8))) {
      primes.push_back(x);
      for (unsigned long j = 2 * x; j <= maxN; j += x)
        sieve[j / 8] &= ~(0x01 << (j % 8));
    }
  delete[] sieve;
  return primes;
}
long long getPow(long long b, long long p) {
  if (b < 2 || p == 1) return b;
  if (p == 0) return 1;
  long long val = getPow(b, p / 2);
  val *= val;
  val %= 1000000007;
  if (p % 2 == 1) {
    val *= b;
    val %= 1000000007;
  }
  return val;
}
void buildSegTree(long node, long b, long e) {
  if (b == e)
    segTree[node] = b;
  else {
    long mid = (b + e) / 2;
    buildSegTree(node * 2, b, mid);
    buildSegTree(1 + node * 2, mid + 1, e);
    if (heights[segTree[node * 2]] <= heights[segTree[1 + node * 2]])
      segTree[node] = segTree[node * 2];
    else
      segTree[node] = segTree[1 + node * 2];
  }
}
long long getMin(long node, long segBeg, long segEnd, long qBeg, long qEnd) {
  if (segEnd < qBeg || segBeg > qEnd) return N + 1;
  if (segBeg >= qBeg && segEnd <= qEnd) return segTree[node];
  long mid = (segBeg + segEnd) / 2;
  long fh = getMin(node * 2, segBeg, mid, qBeg, qEnd);
  long sh = getMin(1 + node * 2, mid + 1, segEnd, qBeg, qEnd);
  if (heights[sh] < heights[fh]) return sh;
  return fh;
}
long dfs(long node, long curLen) {
  if (inq[node] == 0) {
    inq[node] = 1;
    dfs(bff[node], curLen + 1);
  }
  return 0;
}
long dp[10][5];
map<long long, long long> divPos;
long col[200005];
void bfs(long long node) {
  col[node] = 2;
  for (long i = 0; i < graph[node].size(); i++) {
    if (col[graph[node][i]] != 2) bfs(graph[node][i]);
  }
}
long getParent(long node) {
  if (node != parent[node]) {
    parent[node] = getParent(parent[node]);
  }
  return parent[node];
}
void unionNode(long nodeA, long nodeB) {
  long parentA = getParent(nodeA);
  long parentB = getParent(nodeB);
  if (parentA < parentB)
    parent[parentB] = parentA;
  else
    parent[parentA] = parentB;
}
pair<long long, long long> getLongestPath(long long node) {
  long long highestDepth = 0, secondHighestDepth = 0, longestPath = 1;
  pair<long long, long long> lpi;
  for (long i = 0; i < graph[node].size(); i++) {
    if (col[graph[node][i]] < 2) {
      col[graph[node][i]] = 2;
      lpi = getLongestPath(graph[node][i]);
      if (lpi.first > longestPath) longestPath = lpi.first;
      if (lpi.second > highestDepth) {
        secondHighestDepth = highestDepth;
        highestDepth = lpi.second;
      } else if (lpi.second > secondHighestDepth)
        secondHighestDepth = lpi.second;
    }
  }
  if (highestDepth + secondHighestDepth + 1 > longestPath)
    longestPath = highestDepth + secondHighestDepth + 1;
  lpi.first = longestPath;
  lpi.second = highestDepth + 1;
  return lpi;
}
int main(void) {
  long long test_cases = 1, l, seed = 1, B, P;
  cout << setprecision(15) << fixed;
  long long n, t;
  char diffNextp, diffPrevp;
  string s;
  for (long T = 0; T < test_cases; T++) {
    cin >> n;
    long long val = 2, minval, highval = 0;
    cout << 2 << endl;
    for (long long level = 2; level <= n; level++) {
      cout << (level + (long long)1) * (level + (long long)1) * (level) -
                  (level - (long long)1)
           << endl;
    }
  }
  return 0;
}
