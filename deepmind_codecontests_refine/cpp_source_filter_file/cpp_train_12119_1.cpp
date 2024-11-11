#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
void print(T &s) {
  for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
    cout << *it << " ";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < int(n); i++) cin >> p[i];
  int cnt = 0;
  for (int i = 0; i < int(n); i++)
    if (p[i] == i) cnt++;
  if (cnt == n) {
    cout << n << endl;
  } else {
    for (int i = 0; i < int(n); i++) {
      if (p[i] != i && p[p[i]] == i) {
        cout << cnt + 2 << endl;
        break;
      }
    }
    cout << cnt + 1 << endl;
  }
}
