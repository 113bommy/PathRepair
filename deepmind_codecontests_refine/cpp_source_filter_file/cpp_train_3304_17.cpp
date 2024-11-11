#include <bits/stdc++.h>
using namespace std;
template <typename T>
class MinPq : public priority_queue<T, vector<T>, greater<T> > {};
template <typename T>
class MaxPq : public priority_queue<T, vector<T>, less<T> > {};
int a[100000];
int main() {
  int i, n, pos, mn = INT_MAX;
  multimap<int, int> bstree;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  int cycles = n * (mn / n);
  for (i = 0; i < n; i++) {
    a[i] -= cycles;
  }
  for (pos = 0;; pos++) {
    a[pos % n] -= pos;
    if (a[pos % n] <= 0) break;
  }
  cout << pos + 1 << "\n";
  return 0;
}
