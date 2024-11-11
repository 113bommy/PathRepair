#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > G(26);
int main(void) {
  bool invalid = false;
  string n1, n2;
  int indegree[26];
  priority_queue<int, vector<int>, greater<int> > Q;
  fill(indegree, indegree + 26, 0);
  cin >> n;
  cin >> n1;
  while (--n) {
    cin >> n2;
    int i = 0, l1 = n1.size(), l2 = n2.size();
    while (i < l1 && i < l2 && n1[i] == n2[i]) i++;
    if (i == l1 && i < l2) {
      invalid = true;
      break;
    }
    if (i < l1 && i < l2) {
      G[n1[i] - 'a'].push_back(n2[i] - 'a');
      indegree[n2[i] - 'a']++;
    }
    n1 = n2;
  }
  for (int i = 0; i < 26; i++)
    if (!indegree[i]) Q.push(i);
  int cur = 0;
  string ans = "";
  while (!Q.empty()) {
    cur++;
    int u = Q.top();
    ans += (char)('a' + u);
    Q.pop();
    for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++) {
      indegree[*it]--;
      if (indegree[*it] == 0) Q.push(*it);
    }
  }
  if (cur != 26 || invalid)
    cout << "Impossible";
  else
    cout << ans;
  cout << endl;
}
