#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) {
    return false;
  }
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
double dist(double x, double y) { return sqrt(pow(x, 2) + pow(y, 2)); }
vector<long long> BFS(vector<long long> adj[], long long s, bool visited[]) {
  vector<long long> a;
  long long num_of_players = 0;
  queue<long long> q;
  visited[s] = true;
  q.push(s);
  a.push_back(s);
  num_of_players++;
  while (!q.empty()) {
    long long front = q.front();
    q.pop();
    for (long long v : adj[front]) {
      if (visited[v] == false) {
        visited[v] = true;
        q.push(v);
        a.push_back(v);
        num_of_players++;
      }
    }
  }
  return a;
}
pair<vector<vector<long long> >, long long> BFSdis(vector<long long> adj[],
                                                   long long V) {
  vector<vector<long long> > aa;
  vector<vector<long long> > bb;
  bool visited[V];
  for (long long i = 0; i < V; i++) {
    visited[i] = false;
  }
  long long extra = 0;
  long long count = 0;
  for (long long i = 0; i < V; i++) {
    if (visited[i] == false) {
      vector<long long> ans = BFS(adj, i, visited);
      if (ans.size() > 3) {
        aa.push_back(ans);
        return {aa, -1};
      }
      aa.push_back(ans);
    }
  }
  return {aa, 1};
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> adj[n];
    if (m == 0) {
      if (n % 3 != 0) {
        cout << -1 << endl;
        return 0;
      }
      for (long long i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      return 0;
    }
    while (m--) {
      long long ele1, ele2;
      cin >> ele1 >> ele2;
      ele1--;
      ele2--;
      adj[ele1].push_back(ele2);
      adj[ele2].push_back(ele1);
    }
    pair<vector<vector<long long> >, long long> ans = BFSdis(adj, n);
    if (ans.second == -1) {
      cout << -1 << endl;
      return 0;
    } else {
      long long count1 = 0;
      long long count2 = 0;
      long long count3 = 0;
      for (auto team : ans.first) {
        if (team.size() == 3) {
          count3++;
        } else if (team.size() == 2) {
          count2++;
        } else {
          count1++;
        }
      }
      if (count2 > count1) {
        cout << -1 << endl;
        return 0;
      }
      count1 = count1 - count2;
      if (count1 % 3 != 0) {
        cout << -1 << endl;
        return 0;
      }
      vector<vector<long long> > a2;
      vector<long long> a1;
      for (auto team : ans.first) {
        if (team.size() == 3) {
          for (long long x : team) {
            cout << x + 1 << " ";
          }
          cout << endl;
        } else if (team.size() == 2) {
          a2.push_back(team);
        } else {
          a1.push_back(team[0]);
        }
      }
      long long itr = 0;
      for (auto team : a2) {
        for (long long x : team) {
          cout << x + 1 << " ";
        }
        cout << a1[itr] + 1 << " " << endl;
        itr++;
      }
      long long count = 0;
      while (itr < a1.size()) {
        cout << a1[itr] + 1 << " ";
        count++;
        if (count % 3 == 0) {
          cout << endl;
        }
        itr++;
      }
    }
  }
}
