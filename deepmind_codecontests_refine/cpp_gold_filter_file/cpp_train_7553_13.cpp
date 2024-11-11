#include <bits/stdc++.h>
using namespace std;
string vas;
bool cmp(pair<int, string> A, pair<int, string> B) {
  if (A.first == B.first) {
    return A.second > B.second;
  } else {
    return A.first < B.first;
  }
}
int find(vector<pair<int, string>> &v) {
  int i = 0;
  for (auto u : v) {
    if (u.second == vas) {
      return i;
    }
    i++;
  }
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  int n, i, j, point;
  cin >> n;
  string second;
  vector<pair<int, string>> main;
  for (i = 0; i < n; i++) {
    cin >> second >> point;
    main.push_back({point, second});
  }
  int m;
  cin >> m;
  vector<pair<int, string>> v;
  int ara[m];
  for (i = 0; i < m; i++) {
    cin >> ara[i];
  }
  v = main;
  cin >> vas;
  if (m == 0) {
    v = main;
    sort(v.rbegin(), v.rend(), cmp);
    cout << find(v) + 1 << " " << find(v) + 1 << "\n";
    return 0;
  }
  int indx = find(v), low = 0;
  i = 0;
  sort(ara, ara + m);
  if (n == m) {
    v[indx].first += ara[i];
    i++;
  }
  sort(v.rbegin(), v.rend(), cmp);
  indx = find(v);
  low = indx;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (; i < m; i++) {
    pq.push(ara[i]);
  }
  for (i = indx + 1; i < n && (!pq.empty()); i++) {
    while (!pq.empty()) {
      int t = pq.top();
      if ((v[i].first + t) >= v[indx].first) {
        if ((v[i].first + t) == v[indx].first) {
          if (v[i].second > v[indx].second == 0) {
            low++;
            pq.pop();
            break;
          }
        } else {
          pq.pop();
          low++;
          break;
        }
      }
      pq.pop();
    }
  }
  int high = INT_MAX;
  v = main;
  sort(ara, ara + m, greater<int>());
  queue<int> q;
  for (i = 0; i < m; i++) {
    q.push(ara[i]);
  }
  indx = find(v);
  v[indx].first += ara[0];
  q.pop();
  sort(v.rbegin(), v.rend(), cmp);
  for (i = 0; i < n && (!q.empty()); i++) {
    if (v[i].second != vas) {
      v[i].first += q.front();
      q.pop();
    }
  }
  sort(v.rbegin(), v.rend(), cmp);
  high = min(high, find(v));
  v = main;
  sort(ara, ara + m, greater<int>());
  for (i = 0; i < m; i++) {
    q.push(ara[i]);
  }
  indx = find(v);
  v[indx].first += ara[0];
  q.pop();
  sort(v.rbegin(), v.rend(), cmp);
  for (i = 0; i < n && (!q.empty()); i++) {
    if (v[i].second == vas) {
      break;
    } else {
      v[i].first += q.front();
      q.pop();
    }
  }
  for (j = n - 1; j > i && (!q.empty()); j--) {
    v[j].first += q.front();
    q.pop();
  }
  sort(v.rbegin(), v.rend(), cmp);
  high = min(high, find(v));
  cout << high + 1 << " " << low + 1 << endl;
  return 0;
}
