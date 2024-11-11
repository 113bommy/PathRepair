#include <bits/stdc++.h>
using namespace std;
queue<long long> q;
long long one[100005], two[100005], three[100005];
long long t[100005];
long long i, j, k, ti, tj, tk;
int main() {
  long long a, b, c, d, e, x, y, z;
  cin >> i >> j >> k;
  cin >> ti >> tj >> tk;
  cin >> z;
  for (a = 1; a <= z; a++) cin >> t[a];
  q.push((t[1] + ti));
  one[1] = t[1] + ti;
  i--;
  for (a = 2; a <= z; a++) {
    if (i > 0) {
      i--;
      q.push((t[a] + ti));
      one[a] = t[a] + ti;
      continue;
    }
    x = q.front();
    q.pop();
    x = max(x, t[a]);
    one[a] = x + ti;
    q.push((x + ti));
  }
  while (!q.empty()) q.pop();
  q.push(one[1] + tj);
  j--;
  two[1] = one[1] + tj;
  for (a = 2; a <= z; a++) {
    if (j > 0) {
      j--;
      q.push(one[a] + tj);
      two[a] = one[a] + tj;
      continue;
    }
    x = q.front();
    q.pop();
    x = max(x, one[a]);
    two[a] = x + tj;
    q.push(two[a]);
  }
  while (!q.empty()) q.pop();
  q.push(two[1] + tk);
  k--;
  three[1] = two[1] + tk;
  for (a = 2; a <= z; a++) {
    if (k > 0) {
      k--;
      q.push(two[a] + tk);
      three[a] = two[a] + tk;
      continue;
    }
    x = q.front();
    q.pop();
    x = max(x, two[a]);
    three[a] = x + tk;
    q.push(three[a]);
  }
  long long sol;
  sol = 0;
  for (a = 1; a <= z; a++) sol = max(sol, three[a] - t[a]);
  cout << sol << endl;
  return 0;
}
