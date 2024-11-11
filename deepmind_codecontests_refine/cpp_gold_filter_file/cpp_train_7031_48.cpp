#include <bits/stdc++.h>
using namespace std;
template <typename T>
T& input(T& v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
  return v;
}
template <typename T>
T& input_2d(T& v) {
  int N = v.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < v[i].size(); j++) cin >> v[i][j];
  }
}
template <typename T>
T& input_pair(T& v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i].first >> v[i].second;
  return v;
}
template <typename T>
void print(const T& v) {
  int N = v.size();
  for (int i = 0; i < N; i++) cout << v[i] << " ";
}
template <typename T>
void print_2d(T& v) {
  int N = v.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
    cout << '\n';
  }
}
template <typename T>
void print_pair(const T& v) {
  int N = v.size();
  for (int i = 0; i < N; i++) cout << v[i].first << " " << v[i].second << '\n';
}
template <typename T>
inline int digits(const T& N) {
  return (N > 0 ? (int)((log10(N)) + 1) : 0);
}
inline bool ispoweroftwo(int x) { return (x && (!(x & (x - 1)))); }
bool if_integer(double x) {
  if (x - floor(x) == 0 && x > 0)
    return true;
  else
    return false;
}
int binomial(int n, int k) {
  vector<int> C(k + 1, 0);
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, k); j > 0; j--) C[j] = C[j] + C[j - 1];
  }
  return C[k];
}
inline double distance(int a, int b, int c, int d) {
  return sqrt(((long long)(a - c)) * (a - c) + ((long long)(b - d)) * (b - d));
}
class compare {
  bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first > p2.first;
  }
};
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) return (a.second < b.second);
  return (a.first > b.first);
}
bool mysort(const vector<int>& a, const vector<int>& b) {
  return (a.size() < b.size());
}
int BS(vector<int>& arr, int x) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int x = min(min(p1, p2), min(p3, p4));
  if (x <= a)
    cout << 0;
  else if (x > a && x <= b)
    cout << x - a;
  else if (x > b)
    cout << (b - a + 1);
  return 0;
}
