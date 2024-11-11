#include <bits/stdc++.h>
using namespace std;
set<pair<long long int, long long int> > myst;
int main() {
  long long int n, temp;
  cin >> n;
  vector<long long int> strength(n + 1);
  long long int maxstrength = LONG_MIN;
  long long int maxstrpos;
  for (long long int i = 1; i <= n; i++) {
    cin >> temp;
    if (maxstrength < temp) {
      maxstrength = temp;
      maxstrpos = i;
    }
    strength[i] = temp;
  }
  long long int ans = strength[maxstrpos];
  vector<bool> online(n + 1, true);
  vector<vector<long long int> > edge(n + 1);
  vector<set<long long int> > edhe2(n + 1);
  long long int u, v;
  for (long long int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
    edhe2[u].insert(v);
    edhe2[v].insert(u);
  }
  long long int ct = 0;
  for (int i = 1; i <= n; i++) {
    if (strength[i] == strength[maxstrpos]) {
      ct++;
    }
  }
  if (ct == 1) {
    queue<long long int> q;
    q.push(maxstrpos);
    while (!q.empty()) {
      long long int xx = q.front();
      q.pop();
      online[xx] = false;
      for (auto it : edge[xx]) {
        if (online[it]) {
          strength[it]++;
          q.push(it);
          for (auto it2 : edge[it]) {
            if (online[it2]) {
              strength[it2]++;
            }
          }
        }
      }
    }
    ans = LONG_MIN;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, strength[i]);
    }
    cout << ans << "\n";
  } else {
    vector<int> ee;
    for (int i = 1; i <= n; i++) {
      if (strength[i] == strength[maxstrpos]) {
        ee.push_back(i);
      }
    }
    bool ohyeah;
    for (int i = 0; i < ee.size(); i++) {
      ohyeah = true;
      for (int j = 0; j < ee.size(); j++) {
        if (i != j && edhe2[ee[i]].find(ee[j]) == edhe2[ee[i]].end()) {
          ohyeah = false;
          break;
        }
      }
      if (ohyeah) break;
    }
    if (ohyeah) {
      cout << strength[maxstrpos] + 1;
    } else {
      ohyeah = true;
      for (int i = 1; i <= n; i++) {
        if (strength[i] != strength[maxstrpos]) {
          ohyeah = true;
          for (auto it : ee) {
            if (edhe2[i].find(it) == edhe2[i].end()) {
              ohyeah = false;
              break;
            }
          }
          if (ohyeah) break;
        }
      }
      if (ohyeah)
        cout << strength[maxstrpos] + 1;
      else
        cout << strength[maxstrpos] + 2;
    }
  }
  return 0;
}
