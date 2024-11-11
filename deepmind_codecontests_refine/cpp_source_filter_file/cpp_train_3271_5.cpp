#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dgb;
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::set<T>& v) {
  bool first = true;
  os << "[";
  for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <class T>
void isort(T a[], int len, bool INC) {
  for (int i = 1; i < len; i++)
    for (int j = i - 1; j >= 0; j--)
      if ((INC && (a[j + 1] < a[j])) || (!INC && (a[j + 1] > a[j])))
        swap(&a[j + 1], &a[j]);
  return;
}
template <class T>
void readArr(T a[], int len) {
  for (int i = 0; i < len; i++) cin >> a[i];
  return;
}
template <class T>
void printArr(T a[], int len) {
  for (int i = 0; i < len; i++) cout << a[i] << " ";
  cout << endl;
  return;
}
template <class T>
vector<T> slice(vector<T> v, int i, int j) {
  vector<T> b;
  for (int k = i; k < j; k++) b.push_back(v[k]);
  return b;
}
template <class T>
T* slice(T a[], int i, int j) {
  int size = j - i;
  T b[size];
  for (int k = i; k < j; k++) b[k - i] = a[k];
  return b;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << (m * (m - 1) / 2) << endl;
  if (false) {
    for (int i = 0; i < m; i++)
      for (int j = i + 1; j < m; j++) cout << j + 1 << " " << i + 1 << endl;
  } else {
    for (int i = 0; i < m; i++)
      for (int j = i + 1; j < m; j++) cout << i + 1 << " " << j + 1 << endl;
  }
  return 0;
}
