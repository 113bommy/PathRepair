#include <bits/stdc++.h>
using namespace std;
void solveA() {
  int ar[6], n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  cout << ar[n / 2];
}
void solveB() {
  int n;
  cin >> n;
  vector<pair<int, int>> rez;
  pair<int, int> ar[102];
  for (int i = 1; i <= n; i++) {
    cin >> ar[i].first;
    ar[i].second = i;
  }
  sort(ar + 2, ar + n + 1,
       [&](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
  int lastknow = 2;
  for (int i = 1; i < n; i++) {
    if (ar[i].first == 0) {
      cout << "-1";
      return;
    }
    for (int j = 0; j < ar[i].first; j++) {
      rez.push_back(make_pair(ar[i].second, ar[lastknow].second));
      lastknow++;
      if (lastknow > n) {
        cout << n - 1 << endl;
        for (auto &x : rez) {
          cout << x.first << " " << x.second << endl;
        }
        return;
      }
    }
  }
}
bool ar[1002][1002];
int dist[1002][1002];
void solveC() {
  for (int i = 0; i < 1002; i++) {
    for (int j = 0; j < 1002; j++) {
      ar[i][j] = false;
      dist[i][j] = 1e9;
    }
  }
  int n, m, k;
  char c;
  pair<int, int> start;
  pair<pair<int, int>, char> steps[4] = {
      make_pair(make_pair(1, 0), 'D'), make_pair(make_pair(0, -1), 'L'),
      make_pair(make_pair(0, 1), 'R'), make_pair(make_pair(-1, 0), 'U')};
  scanf("%d%d%d%c", &n, &m, &k, &c);
  if (k & 1) {
    cout << "IMPOSSIBLE";
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%c", &c);
      ar[i][j] = (c == '*' ? false : true);
      if (c == 'X') start = make_pair(i, j);
    }
    scanf("%c", &c);
  }
  bool flag = false;
  for (int i = 0; i < 4; i++) {
    flag |= ar[start.first + steps[i].first.first]
              [start.second + steps[i].first.second];
  }
  if (!flag) {
    cout << "IMPOSSIBLE";
    return;
  }
  queue<pair<int, int>> q;
  dist[start.first][start.second] = 0;
  q.push(start);
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> to = make_pair(cur.first + steps[i].first.first,
                                    cur.second + steps[i].first.second);
      if (ar[to.first][to.second] &&
          dist[to.first][to.second] > dist[cur.first][cur.second] + 1) {
        q.push(to);
        dist[to.first][to.second] = dist[cur.first][cur.second] + 1;
      }
    }
  }
  pair<int, int> cur = start;
  while (k) {
    for (int i = 0; i < 4; i++) {
      pair<int, int> to = make_pair(cur.first + steps[i].first.first,
                                    cur.second + steps[i].first.second);
      if (dist[to.first][to.second] < k) {
        printf("%c", steps[i].second);
        k--;
        cur = to;
        break;
      }
    }
  }
}
long long a[20002];
void solveD() {
  int n, k, t;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a[t]++;
  }
  if (k == 0) {
    long long rez = 0;
    for (int i = 0; i < 10001; i++) rez += (a[i] - 1) * a[i] / 2;
    cout << rez;
    return;
  }
  vector<int> masks;
  int kol;
  for (int i = 0; i < 16384; i++) {
    kol = 0;
    for (int j = 1; j < 16384; j <<= 1) {
      if (i & j) kol++;
    }
    if (kol == k) masks.push_back(i);
  }
  long long rez = 0;
  int tmp;
  for (int i = 0; i < 10001; i++) {
    if (!a[i]) continue;
    for (auto &x : masks) {
      rez += (a[i] * a[i ^ x]);
    }
  }
  rez /= 2;
  cout << rez;
}
int main() {
  solveD();
  return 0;
}
