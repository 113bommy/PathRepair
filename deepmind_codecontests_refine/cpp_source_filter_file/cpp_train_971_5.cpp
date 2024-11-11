#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
void chmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void chmax(T &x, T y) {
  x = max(x, y);
}
template <typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
  s << "(" << x.first << ", " << x.second << ")";
  return s;
}
template <typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
  s << "[";
  bool was = false;
  for (auto it : x) {
    if (was) {
      s << ", ";
    }
    was = true;
    s << it;
  }
  s << "]";
  return s;
}
const int maxn = 1e5 + 5;
const int inf = 1e9;
char a[2][maxn];
int d[2][maxn];
int main() {
  srand(time(NULL));
retry:
  int n, k;
  scanf("%d %d\n", &n, &k);
  scanf("%s\n", a[0] + 1);
  scanf("%s\n", a[1] + 1);
  queue<pair<int, int>> q;
  q.push(make_pair(0, 1));
  fill(d[0], d[0] + maxn, inf);
  fill(d[1], d[1] + maxn, inf);
  d[0][1] = 0;
  auto yes = []() {
    cout << "YES" << endl;
    exit(0);
  };
  while (!q.empty()) {
    int s = q.front().first;
    int v = q.front().second;
    q.pop();
    if (v + k > n) {
      yes();
    }
    if (a[s][v + 1] == '-' && d[s][v + 1] == inf) {
      d[s][v + 1] = d[s][v] + 1;
      q.push(make_pair(s, v + 1));
    }
    if (v - 1 >= 0 && a[s][v - 1] == '-' && v - 1 > d[s][v] + 1 &&
        d[s][v - 1] == inf) {
      d[s][v - 1] = d[s][v] + 1;
      q.push(make_pair(s, v + 1));
    }
    if (a[1 - s][v + k] == '-' && d[1 - s][v + k] == inf) {
      d[1 - s][v + k] = d[s][v] + 1;
      q.push(make_pair(1 - s, v + k));
    }
  }
  cout << "NO" << endl;
  return 0;
}
