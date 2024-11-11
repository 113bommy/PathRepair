#include <bits/stdc++.h>
using namespace std;
map<int, int> mp, mpp;
set<int> st;
vector<int> v;
set<int>::iterator P;
long long A[200002], n, m, i, j, t, k, x, y;
string s, s1;
long long a, b, c, cost;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    x = 0;
    cin >> n >> a >> b >> s;
    cost = n * a + (n + 1) * b;
    for (i = 0; i < n - 1; i++) {
      if (s[i] == '0' && x == 0 && s[i + 1] != '1')
        continue;
      else if (s[i] == '0' && x == 0)
        cost += a, x = 1;
      else if (s[i] == '1')
        cost += b;
      else if (s[i] == '0' && x == 1) {
        k = 0;
        for (j = i; j < n; j++)
          if (s[j] == '0')
            k++;
          else
            break;
        k--;
        if (j == n)
          cost += a, x = 0;
        else if (!k)
          cost += b;
        else
          cost += min(2 * a, b * k) + b;
        i = j - 1;
      }
    }
    if (x == 1) cost += a + b;
    cout << cost << endl;
  }
  return 0;
}
