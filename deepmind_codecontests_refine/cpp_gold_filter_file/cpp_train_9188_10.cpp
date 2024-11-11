#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long int inf64 = LLONG_MAX;
long long int query(long long int i, long long int j) {
  cout << "? " << i << ' ' << j << endl;
  long long int res;
  cin >> res;
  assert(res != -1);
  return res;
}
void report(vector<long long int> ans) {
  cout << "! ";
  long long int i;
  for (i = 1; i < ans.size(); i++) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int i, n;
  cin >> n;
  set<int> idx, num;
  for (i = 1; i <= n; i++) {
    idx.insert(i);
    num.insert(i);
  }
  vector<long long int> ans(n + 1);
  while (idx.size() > 1) {
    long long int a, b;
    a = *(idx.begin());
    idx.erase(a);
    b = *(idx.begin());
    idx.erase(b);
    long long int q1, q2;
    q1 = query(a, b);
    q2 = query(b, a);
    if (q1 > q2) {
      ans[a] = q1;
      num.erase(q1);
      idx.insert(b);
    } else {
      ans[b] = q2;
      num.erase(q2);
      idx.insert(a);
    }
  }
  ans[*(idx.begin())] = *num.begin();
  report(ans);
  return 0;
}
