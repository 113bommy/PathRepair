#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  deque<long long> q;
  map<int, int> m;
  int l = 0, r = 1;
  while (n--) {
    char ch;
    int a;
    cin >> ch >> a;
    if (ch == 'L') {
      q.push_front(l);
      m[a] = l;
      l--;
    } else if (ch == 'R') {
      q.push_back(r);
      m[a] = r;
      r++;
    } else {
      long long ind = lower_bound(q.begin(), q.end(), m[a]) - q.begin();
      cout << min(ind, (long long)((int)q.size() - 1 - ind)) << endl;
    }
  }
}
