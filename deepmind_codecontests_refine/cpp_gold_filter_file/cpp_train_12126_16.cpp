#include <bits/stdc++.h>
using namespace std;
vector<string> names;
vector<int> adj[27];
bool vis[26];
stack<int> st;
void toposort(int node, set<int> dup) {
  vis[node] = 1;
  dup.insert(node);
  for (auto it : adj[node]) {
    if (dup.count(it)) {
      cout << "Impossible";
      exit(0);
    }
    if (!vis[it]) {
      toposort(it, dup);
    }
  }
  st.push(node + 'a');
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    names.push_back(s);
  }
  for (int i = 1; i < names.size(); i++) {
    string x = names[i - 1];
    string y = names[i];
    for (int j = 0; j < x.size(); j++) {
      if (j == y.size()) {
        cout << "Impossible";
        return 0;
      } else {
        if (x[j] != y[j]) {
          adj[x[j] - 'a'].push_back(y[j] - 'a');
          break;
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      set<int> dup;
      toposort(i, dup);
    }
  }
  while (!st.empty()) {
    cout << (char)(st.top());
    st.pop();
  }
  return 0;
}
