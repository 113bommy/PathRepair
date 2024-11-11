#include <bits/stdc++.h>
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
using namespace std;
int main(int argc, char const *argv[]) {
  string a, b;
  cin >> a >> b;
  int al = a.size(), bl = b.size();
  sort(b.rbegin(), b.rend());
  int pos = 0;
  for (int i = 0; i < al; i++) {
    if (pos < bl - 1 && a[i] < b[pos])
      cout << b[pos++];
    else
      cout << a[i];
  }
  cout << endl;
  return 0;
}
