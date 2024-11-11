#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > q;
int n;
long long k;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int sz = 7777;
int a[sz][sz];
const long long mod = 1000000007;
int main() {
  double t1 = clock();
  cin >> k >> n;
  for (int(i) = 0; (i) < (n); ++(i)) {
    int first, second;
    cin >> first >> second;
    first += sz / 2;
    second += sz / 2;
    a[first][second] = -1;
  }
  int line = 0;
  int step = 0;
  q.push(make_pair(sz / 2, sz / 2));
  a[sz / 2][sz / 2] = 1;
  int last = 0;
  long long tot = 1;
  do {
    ++step;
    int prev = q.size();
    for (int num = 0; num < prev; ++num) {
      pair<int, int> cur = q.front();
      q.pop();
      for (int(k) = 0; (k) < (8); ++(k)) {
        pair<int, int> np = make_pair(cur.first + dx[k], cur.second + dy[k]);
        if (!a[np.first][np.second]) {
          a[np.first][np.second] = 1;
          q.push(np);
        }
      }
    }
    if (q.size() - prev == 28)
      line++;
    else if (q.size() == prev) {
      cout << tot << endl;
      return 0;
    } else
      line = 0;
    tot = (tot + q.size()) % mod;
    if (clock() - t1 > 1.95 * CLOCKS_PER_SEC) break;
  } while (line < 3 && step < k);
  k -= step;
  k %= mod;
  tot = (tot + (k * q.size())) % mod;
  long long tmp = (k * (k + 1) / 2) % mod;
  tot = (tot + tmp * 28) % mod;
  cout << tot << endl;
}
