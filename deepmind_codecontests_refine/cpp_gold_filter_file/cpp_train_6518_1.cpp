#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e1 + 4;
vector<int> circle;
bool vis[N];
bool bad_Relation[N];
int parent[N];
ll chk[N];
int color[N];
int tim[N];
int dis[N];
int position[N];
vector<int> adj[N];
vector<int> adj1[N];
vector<int> graph[N];
bool has_cycle;
int maxdis, maxnode, Totnode, depth = 1;
bool ok;
queue<int> q;
stack<int> stk;
vector<int> solution;
int indegree[N];
int go[N];
int to[N];
ll x1, x2, x3, x4, x5, x6;
string ss;
int gn, gk;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  int cas = 0;
  while (t--) {
    int n, m, i, j, cnt = 0, cnt1 = 0, cnt2 = 0, even = 0, odd = 0, len, k, r,
                    l, z = 0, x = 0, y = 0, flag = 0, sum = 0, tottal = 0;
    int a = 0, b = 0, c = 0, d = 0, ans = 0, rem, quot, zero = 0, fst = 0,
        null = 0, snd = 0, lst = 0, rone = 0, one = 0, pos = 0, neg = 0,
        mn = INT_MAX, mx = INT_MIN;
    char ch;
    int h1, h2, m1, m2, h;
    int velo1, velo2, ac1, ac2, tim, hour, mint, sec;
    int node, edge, u, v, cost;
    int bst, wrst;
    double nd, ad, bd, cd, dd, xd, sumd = 0.00;
    string str, str1 = "", str2 = "", str3 = "", strstore1 = "", strstore2 = "";
    cin >> n;
    ll arr[n + 4][6];
    ll brr[n + 4];
    memset(brr, 0, sizeof(brr));
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
          if (i == j or j == k or k == i) {
            continue;
          }
          sum = 0;
          for (a = 0; a < 5; a++) {
            sum += (arr[j][a] - arr[i][a]) * (arr[k][a] - arr[i][a]);
          }
          if (sum > 0) {
            brr[i] = 1;
            break;
          }
        }
        if (brr[i]) {
          break;
        }
      }
    }
    for (i = 0; i < n; i++) {
      if (!brr[i]) {
        ans++;
      }
    }
    cout << ans << endl;
    for (i = 0; i < n; i++) {
      if (!brr[i]) {
        cout << i + 1 << endl;
      }
    }
  }
  return 0;
}
