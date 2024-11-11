#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long> V, v;
  long i, j, c, a, b, n;
  string s;
  cin >> s;
  v.push_back(0);
  V.push_back(0);
  for (i = 0; i < s.size(); i++)
    if ((s[i] >= 'A') && (s[i] <= 'Z'))
      V.push_back(V[i]);
    else
      V.push_back(V[i] + 1);
  long h = 0;
  for (i = s.size() - 1; i >= 0; i--) {
    if ((s[i] >= 'a') && (s[i] <= 'z'))
      v.push_back(v[h]);
    else
      v.push_back(v[h] + 1);
    h++;
  }
  reverse(v.begin(), v.end());
  n = min(v[0], V[V.size() - 1]);
  for (i = 1; i < V.size(); i++)
    if (v[i] + V[i] < n) n = v[i] + V[i];
  cout << n;
  return 0;
}
