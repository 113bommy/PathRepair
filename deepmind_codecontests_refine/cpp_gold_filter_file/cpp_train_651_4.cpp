#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  else {
    long long op = sqrt(n);
    for (long long i = 3; i < op + 1; i += 2) {
      if (n % i == 0) return false;
    }
    return true;
  }
}
class Graph {
  int V;
  list<int> *adj;

 public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isReachable(int s, int d);
};
Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
bool Graph::isReachable(int s, int d) {
  if (s == d) return true;
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++) visited[i] = false;
  list<int> queue;
  visited[s] = true;
  queue.push_back(s);
  list<int>::iterator i;
  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      if (*i == d) return true;
      if (!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
  return false;
}
long long nextPowerOf2(long long n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
long long highestPowerof2(long long n) {
  long long p = (long long)log2(n);
  return (long long)pow(2, p);
}
struct edge {
  long long u;
  long long v;
};
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long findlcm(int arr[], int n) {
  long long ans = arr[0];
  for (int i = 1; i < n; i++) ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
  return ans;
}
void prefixArray(int arr[], int n, int prefixarr[]) {
  prefixarr[1] = arr[1];
  for (long long i = 2; i < n + 1; i += 1) {
    prefixarr[i] = prefixarr[i - 1] + arr[i];
  }
}
int countDivisors(int n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (long long i = 1; i < t + 1; i += 1) {
    long long n;
    cin >> n;
    for (long long j = 4 * n; j >= (2 * n + 2); j -= 2) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}
