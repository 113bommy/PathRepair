#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18L + 5;
map<int, vector<int>> adj;
map<int, bool> visited;
long long d[N];
int parent[N];
string s, k;
int n;
set<string> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> k;
    if (s.compare(k.substr(0, s.size())) == 0) st.insert(k);
  }
  if (st.size() > 1)
    cout << *st.begin();
  else
    cout << s;
  return 0;
}
