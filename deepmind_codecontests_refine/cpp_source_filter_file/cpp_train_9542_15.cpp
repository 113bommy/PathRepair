#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string v[100005];
int c[100005];
map<string, int> gr;
int minc[100005];
int main() {
  int i, j;
  cin >> n >> k >> m;
  for (i = 1; i <= n; i++) cin >> v[i];
  for (i = 1; i <= n; i++) cin >> c[i];
  for (i = 1; i <= k; i++) {
    minc[i] = INT_MAX;
    int x;
    cin >> x;
    while (x--) {
      int p;
      cin >> p;
      gr[v[p]] = i;
      minc[i] = min(minc[i], c[p]);
    }
  }
  long long rez = 0;
  for (i = 1; i <= k; i++) {
    string a;
    cin >> a;
    rez += minc[gr[a]];
  }
  cout << rez;
  return 0;
}
