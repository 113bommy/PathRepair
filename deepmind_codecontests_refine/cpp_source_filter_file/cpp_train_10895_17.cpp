#include <bits/stdc++.h>
using namespace std;
int n, qr;
vector<pair<int, int> > q[100005];
vector<int> Set;
int l, x, v[100005], sol[100005];
bool inSet[10000000];
int main() {
  cin >> n >> qr;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= qr; i++) {
    scanf("%d%d", &l, &x);
    q[l].push_back({x, i});
  }
  Set.push_back(0);
  inSet[0] = 1;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (inSet[v[i]])
      ans = (ans * 2) % 1000000000 + 7;
    else {
      int sz = Set.size();
      for (int j = 0; j < sz; j++) {
        Set.push_back(Set[j] ^ v[i]);
        inSet[Set.back()] = 1;
      }
    }
    for (auto it : q[i]) {
      sol[it.second] = ans * inSet[it.first];
    }
  }
  for (int i = 1; i <= qr; i++) printf("%d\n", sol[i]);
  return 0;
}
