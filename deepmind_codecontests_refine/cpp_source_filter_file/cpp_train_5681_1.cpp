#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first - b.first) * (b.second - c.second) -
       (b.first - c.first) * (a.second - b.second)) < 0.0)
    return 1;
  else
    return 0;
}
int flag[200000];
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 2];
  int mi = 100;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mi = min(mi, a[i]);
  }
  pair<int, int> ar[n * n + 2];
  for (int k = mi; k >= 1; k--) {
    priority_queue<pair<int, int> > pq;
    for (int j = 1; j <= n; j++) {
      pq.push(make_pair(a[j] - k, j));
    }
    pair<int, int> sa = make_pair(0, 0);
    int sz = 0;
    int tot = 0;
    while (!pq.empty()) {
      pair<int, int> first = pq.top();
      pq.pop();
      pair<int, int> second = pq.top();
      pq.pop();
      if (first.first == 0) break;
      if (second.first == 0) {
        sa = first;
        break;
      }
      first.first--;
      second.first--;
      ar[++sz] = make_pair(first.second, second.second);
      flag[sz] = 1;
      pq.push(first);
      pq.push(second);
    }
    for (int i = 1; i <= sz && sa.first; i++) {
      if (ar[i].first == sa.second || ar[i].second == sa.second)
        continue;
      else {
        sa.first--;
        flag[i] = 0;
      }
    }
    if (sa.first == 0) {
      printf("%d\n", k);
      printf("%d\n", sz);
      for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= n; j++) {
          if (flag[i] == 0) {
            if (j == ar[i].first || ar[i].second == j || j == sa.second)
              printf("1");
            else
              printf("0");
          } else {
            if (j == ar[i].first || ar[i].second == j)
              printf("1");
            else
              printf("0");
          }
        }
        puts("");
      }
      return 0;
    }
  }
  printf("0\n");
  int tot = 0;
  tot = max(a[1], a[2]);
  for (int i = 3; i <= n; i++) tot += a[i];
  printf("%d\n", tot);
  int l = max(a[1], a[2]);
  for (int i = 1; i <= l; i++) {
    printf("11");
    for (int j = 3; j <= n; j++) printf("0");
    puts("");
  }
  for (int i = 3; i <= n; i++) {
    for (int cnt = 1; cnt <= a[i]; cnt++) {
      for (int j = 1; j <= n; j++) {
        if (j == i || j == i - 1)
          printf("1");
        else
          printf("0");
      }
      puts("");
    }
  }
  return 0;
}
