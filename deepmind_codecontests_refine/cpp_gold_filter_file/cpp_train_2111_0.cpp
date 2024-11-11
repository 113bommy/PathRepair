#include <bits/stdc++.h>
using namespace std;
const long int N = 100005;
long long n, m, i, j, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    cin >> n;
    char ch;
    long p, pos = 0, total = 2 * n, i = -1;
    priority_queue<long> pq;
    bool f = 1, b[2 * N];
    long a[N];
    vector<long> v;
    priority_queue<long, vector<long>, greater<long> > recheck;
    while (total--) {
      cin >> ch;
      i++;
      if (ch == '+')
        pq.push(pos++), b[i] = 0;
      else {
        cin >> p;
        if (pq.empty()) {
          f = 0;
          continue;
        }
        long val = pq.top();
        pq.pop();
        a[val] = p;
        b[i] = 1;
        v.push_back(p);
      }
    }
    if (!f) {
      cout << "NO\n";
      continue;
    }
    pos = 0;
    k = 0;
    for (i = 0; i < 2 * n; i++) {
      if (b[i] == 1) {
        long val = recheck.top();
        recheck.pop();
        if (val != v[k]) {
          f = 0;
          break;
        } else
          k++;
      } else
        recheck.push(a[pos++]);
    }
    if (!f) {
      cout << "NO\n";
      continue;
    } else {
      cout << "YES\n";
      for (i = 0; i < n; i++) cout << a[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}
