#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string S[100005];
long long cost[100005];
map<string, int> M;
long long min_cost[100005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = int(0); i < int(n); i++) {
    cin >> S[i];
    M[S[i]] = i;
  }
  for (int i = int(0); i < int(n); i++) {
    cin >> cost[i];
  }
  int l, a, mini;
  vector<int> aux;
  for (int i = int(0); i < int(k); i++) {
    cin >> l;
    mini = INT_MAX;
    aux.clear();
    for (int j = int(0); j < int(l); j++) {
      cin >> a;
      a--;
      aux.push_back(a);
      if (cost[a] < mini) {
        mini = cost[a];
      }
    }
    for (int j = int(0); j < int(l); j++) {
      min_cost[aux[j]] = mini;
    }
  }
  string str;
  long long ans = 0;
  for (int i = int(0); i < int(m); i++) {
    cin >> str;
    ans += min_cost[M[str]];
  }
  cout << ans << '\n';
}
