#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void sary(T* st, T* nd) {
  while (st < nd) cin >> *st++;
}
template <class T>
inline double sarys(T* st, T* nd, T sum) {
  while (st < nd) {
    cin >> *st++;
    sum += *st;
  }
  return sum;
}
template <class T>
inline void saryp(T* st, T* nd) {
  while (st < nd) {
    cout << *st++ << " ";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  int min1, min2, min3, max1, max2, max3;
  cin >> min1 >> max1;
  cin >> min2 >> max2;
  cin >> min3 >> max3;
  if (max1 + max2 + min3 <= n) {
    cout << max1 << " " << max2 << " " << n - max1 - max2 << "\n";
  } else if (max1 + min2 + min3 <= n) {
    cout << max1 << " " << n - max1 - min3 << " " << min3 << "\n";
  } else {
    cout << n - min2 - min3 << " " << min2 << " " << min3 << "\n";
  }
  return 0;
}
