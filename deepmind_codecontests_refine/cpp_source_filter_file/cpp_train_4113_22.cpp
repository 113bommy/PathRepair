#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, used[404] = {0}, c = 0;
  long long int s;
  pair<int, int> u;
  vector<pair<long long int, pair<int, int>>> v;
  cin >> n;
  for (i = 2; i <= (2 * n); i++) {
    for (j = 1; j < i; j++) {
      cin >> s;
      u = make_pair(i, j);
      v.push_back(make_pair(s, u));
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (i = 0; i < v.size(); i++) {
    if (c == n)
      break;
    else {
      u = v[i].second;
      if (used[u.first] == 0 && used[u.second] == 0) {
        used[u.first] = u.second;
        used[u.second] = u.first;
        c++;
      }
    }
  }
  for (i = 1; i <= (2 * n); i++) cout << used[i] << " ";
}
