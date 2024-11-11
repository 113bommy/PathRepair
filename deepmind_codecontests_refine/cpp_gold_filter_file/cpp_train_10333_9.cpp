#include <bits/stdc++.h>
using namespace std;
int n;
int ap[1005];
int ind[1005];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
inline bool check(int pos) {
  if (pos > n) pos -= n;
  if (ap[pos]) return 0;
  return 1;
}
inline int real(int ind) {
  if (ind > n) return ind - n;
  return ind;
}
int main() {
  scanf("%d", &n);
  if (n <= 3) {
    cout << 0;
    return 0;
  }
  vector<int> sol;
  int Max = 0, k = 1;
  for (int i = 2; i <= n - 1; ++i) {
    int cnt = n / i + ((n % i) > 0);
    if (n - i + 1 - cnt > Max) {
      Max = n - i + 1 - cnt;
      k = i;
    }
  }
  for (int i = 1; i <= n; i += k) {
    int nr = 0;
    for (int j = i; j <= min(i + k - 1, n); ++j) ind[j] = ++nr;
  }
  ind[n] = k;
  int NR = 0;
  for (int i = 1; i <= n; ++i) {
    if (ind[i] != k) {
      pq.push({ind[i], i});
      ++NR;
    }
  }
  int rep = 0;
  while (NR >= k) {
    if (NR == k) ++rep;
    if (rep == 10) break;
    int cnt = k;
    cout << k;
    while (cnt--) {
      int pos = pq.top().second;
      pq.pop();
      ap[pos] = 1;
      --NR;
      cout << " " << pos;
    }
    cout << endl;
    int x;
    cin >> x;
    for (int i = x; i <= x + k - 1; ++i) {
      if (ap[real(i)]) {
        ap[real(i)] = 0;
        pq.push({ind[real(i)], real(i)});
        ++NR;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}
