#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1, x2), gn(x3);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % m)
    if (b & 1) ans = (long long)ans * a % m;
  return ans;
}
multiset<pair<int, int> > s;
pair<int, int> p[200010];
int arr[200010], nn;
vector<int> pos[200010];
int ans[200010];
int main() {
  int n, k;
  gn(n, k);
  for (int i = 0; i < n; i++) {
    gn(p[i].first, p[i].second);
    arr[nn++] = p[i].first;
    arr[nn++] = p[i].first + k;
  }
  sort(arr, arr + nn);
  nn = unique(arr, arr + nn) - arr;
  for (int i = 0; i < n; i++) {
    p[i].first = lower_bound(arr, arr + nn, p[i].first) - arr;
    pos[p[i].first].push_back(p[i].second);
  }
  for (int i = 0; i < nn - 1; i++) {
    for (int j = 0; j < pos[i].size(); j++) {
      int u = pos[i][j];
      s.insert(pair<int, int>(u, 1));
      s.insert(pair<int, int>(u + k, -1));
    }
    int id = lower_bound(arr, arr + nn, arr[i] - k) - arr;
    if (arr[id] == arr[i] - k) {
      for (int j = 0; j < pos[id].size(); j++) {
        int u = pos[id][j];
        s.erase(s.find(pair<int, int>(u, 1)));
        s.erase(s.find(pair<int, int>(u + k, -1)));
      }
    }
    int N = 0;
    for (multiset<pair<int, int> >::iterator it = s.begin(); it != s.end();
         it++) {
      p[N++] = *it;
    }
    int first = arr[i + 1] - arr[i];
    int u = 0;
    for (int j = 0; j < N - 1; j++) {
      u += p[j].second;
      ans[u] += (long long)first * (p[j + 1].first - p[j].first);
    }
  }
  for (int i = 1; i <= n; i++) printsp(ans[i]);
}
