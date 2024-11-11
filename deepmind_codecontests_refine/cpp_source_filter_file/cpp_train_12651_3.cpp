#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e7 + 1;
const int KMAX = 50 + 1;
const int MOD = 1e9 + 7;
const int GMAX = 1e3 + 1;
const int GNMAX = 1e2 + 1;
const int GMMAX = 1e3 + 2;
list<int> graph[GMAX];
int path[GMAX] = {-1};
bool visit[GMAX] = {false};
int E, V, u, v;
int x[GNMAX], y[GNMAX], Head[GNMAX] = {0}, Adj[GMMAX];
void indinhke(int u) {
  for (int v = Head[u] + 1; v <= Head[u + 1]; v++) cout << Adj[v] << endl;
}
void DFS(int v) {
  visit[v] = true;
  list<int>::iterator i;
  for (i = graph[v].begin(); i != graph[v].end(); i++) {
    if (!visit[*i]) {
      path[*i] = v;
      DFS(*i);
    }
  }
}
void BFS(int s) {
  queue<int> q;
  visit[s] = true;
  q.push(s);
  list<int>::iterator i;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    for (i = graph[s].begin(); i != graph[s].end(); i++) {
      if (!visit[*i]) {
        visit[*i] = true;
        q.push(*i);
        path[*i] = s;
      }
    }
  }
}
int lienthong(int n, int graphs[GMAX][GMAX]) {
  int dd[GMAX] = {0};
  bool check = true;
  int dem = 0, i, j, res = 0;
  do {
    j = 0;
    while (dd[j] == 1) j++;
    dem++;
    res++;
    dd[j] = 1;
    do {
      check = true;
      for (i = 0; i < n; i++) {
        if (dd[i] == 1) {
          for (j = 0; j < n; j++) {
            if (dd[j] == 0 && graphs[i][j] > 0) {
              dd[j] = 1;
              check = false;
              dem++;
              if (dem == n) return res;
            }
          }
        }
      }
    } while (!check);
  } while (dem < n);
  return res;
}
void printGr(int u, int v, int back[]) {
  if (u == v)
    cout << v << ' ';
  else {
    if (back[v] == -1)
      cout << "Khong co duong di";
    else {
      printGr(u, back[v], back);
      cout << v << ' ';
    }
  }
}
int binarysearch(long long a[], int i, int j, long long x) {
  int l = i, r = j;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == x)
      return mid;
    else if (a[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long LCM(int a, int b) { return (a * b) / gcd(a, b); }
int n, a[NMAX], dd[NMAX] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  int res = 0, ma = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], dd[a[i]] += i;
    if (dd[a[i]] > ma) ma = dd[a[i]], res = a[i];
  }
  cout << res;
  return 0;
}
