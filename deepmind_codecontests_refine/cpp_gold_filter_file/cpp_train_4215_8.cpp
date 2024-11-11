#include <bits/stdc++.h>
using namespace std;
const int N = 105;
string name[N];
int marked[N];
vector<int> adj[N], top_sort;
int first_differ(string &s, string &t) {
  for (int i = 0; i < min(s.length(), t.length()); ++i)
    if (s[i] != t[i]) return i;
  return -1;
}
bool is_dag(int v) {
  marked[v] = 1;
  bool ans = true;
  for (auto i : adj[v])
    if (not marked[i])
      ans &= is_dag(i);
    else if (marked[i] == 1)
      return false;
  marked[v] = 2;
  top_sort.push_back(v);
  return ans;
}
void add_edge(char a, char b) { adj[a - 'a'].push_back(b - 'a'); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> name[i];
    if (i) {
      int fd = first_differ(name[i - 1], name[i]);
      if (fd == -1) {
        if (name[i - 1].length() > name[i].length()) {
          cout << "Impossible";
          return 0;
        }
        continue;
      }
      add_edge(name[i][fd], name[i - 1][fd]);
    }
  }
  bool dag = true;
  for (int i = 0; i < 26; ++i)
    if (not marked[i]) dag &= is_dag(i);
  if (dag)
    for (auto i : top_sort) cout << static_cast<char>(i + 'a');
  else
    cout << "Impossible";
}
