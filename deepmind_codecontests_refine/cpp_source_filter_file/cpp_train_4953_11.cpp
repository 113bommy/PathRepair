#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  cin >> x;
  return x;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) in >> vec[i];
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) out << vec[i] << " ";
  return out;
}
int main() {
  int n = in(), m = in();
  if (m == 2 && n >= 5) {
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i) printf("%d %d\n", i + 1, i + 2);
  } else if (m == 3 && n >= 5) {
    cout << 2 * n - 5 << endl;
    for (int i = 0; i < n - 1; ++i) printf("%d %d\n", i + 1, i + 2);
    for (int i = 0; i < n - 4; ++i) {
      printf("%d %d\n", 3, i + 5);
    }
  } else
    printf("%d", -1);
  return 0;
}
