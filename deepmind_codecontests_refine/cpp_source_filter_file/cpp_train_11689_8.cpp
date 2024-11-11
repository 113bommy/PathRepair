#include <bits/stdc++.h>
using namespace std;
template <typename T>
void PrArr(const T a[], int len) {
  for (int i = 0; i <= len; i++) cout << a[i] << " ";
  cout << endl;
}
template <typename T>
void PrVec(const vector<T> a) {
  for (auto it : a) cout << it << " ";
  cout << endl;
}
template <class T>
inline void read(T &res) {
  char c;
  T flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  res *= flag;
}
const int MAX = 0x7ffffff;
const int MIN = 0xcf;
int test;
void slove() {
  int n, x;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < 3; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < 3; i++) {
    cin >> x;
    b.push_back(x);
  }
  int ans1 = INT_MAX;
  vector<pair<int, int> > ord;
  ord.push_back({0, 0});
  ord.push_back({0, 2});
  ord.push_back({1, 1});
  ord.push_back({1, 0});
  ord.push_back({2, 2});
  ord.push_back({2, 1});
  do {
    vector<int> a1 = a, b1 = b;
    for (int i = 0; i < ord.size(); i++) {
      int cnt = min(a1[ord[i].first], b1[ord[i].second]);
      a1[ord[i].first] -= cnt;
      b1[ord[i].second] -= cnt;
    }
    int cur = min(a1[0], b1[1]) + min(a1[1], b1[1]) + min(a1[2], b1[0]);
    ans1 = min(ans1, cur);
  } while (next_permutation(ord.begin(), ord.end()));
  int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  cout << ans1 << " " << ans2 << endl;
}
int main() { slove(); }
