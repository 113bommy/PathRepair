#include <bits/stdc++.h>
using namespace std;
int arr1[2100000];
int arr2[2100000];
int main() {
  long long s, x, c = 0;
  cin >> s >> x;
  long long t = s - x;
  for (int i = 0; i <= 60; i++) {
    if ((1LL << (60 - i)) & x) {
      c++;
    } else {
      if (t >= (1LL << (61 - i))) {
        t -= (1LL << (61 - i));
      }
    }
  }
  if (t != 0)
    cout << 0 << endl;
  else if (s == x) {
    cout << (1LL << (c)) - 2 << endl;
  } else {
    cout << (1LL << (c)) << endl;
  }
  return 0;
}
