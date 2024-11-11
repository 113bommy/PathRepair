#include <bits/stdc++.h>
using namespace std;
string a;
int n, k;
priority_queue<pair<string, int>, vector<pair<string, int> >,
               greater<pair<string, int> > >
    q;
int main() {
  cin >> a >> k;
  n = a.length();
  if (k > n * (n + 1) / 2) return puts("No such line.") && 0;
  for (int i = 0; i < n; i++) {
    pair<string, int> t;
    t.first += a[i];
    t.second = i;
    q.push(t);
  }
  while (!q.empty()) {
    pair<string, int> t = q.top();
    q.pop();
    k--;
    if (!k) {
      cout << t.first << endl;
      break;
    }
    if (t.second + 1 < n)
      q.push(pair<string, int>(t.first + a[t.second + 1], t.second + 1));
  }
  return 0;
}
