#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
template <class T1, class T2, class T3>
void printTuple(tuple<T1, T2, T3> t) {
  cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
}
template <class T1, class T2>
void printPair(pair<T1, T2> p) {
  cout << p.first << " " << p.second << '\n';
}
template <class T>
void printArray(vector<T> arr) {
  for (int i = 0; i < int((arr).size()); i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  int avg = sum / n;
  cout << n - (sum - avg * n != 0) << '\n';
}
