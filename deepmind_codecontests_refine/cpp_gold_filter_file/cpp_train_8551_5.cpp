#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>
void tomax(T& a, T b) {
  a = max(a, b);
}
template <class T>
void tomin(T& a, T b) {
  a = min(a, b);
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a > b) swap(a, b);
  int def = b - a;
  if (def > a) {
    int num = INF;
    for (int i = 1; i * i <= def; i++) {
      if (def % i == 0) {
        int tow = def / i;
        if (i >= a) tomin(num, i);
        if (tow >= a) tomin(num, tow);
      }
    }
    cout << num - a << endl;
  } else if (a == b)
    cout << 0 << endl;
  else {
    if (a % def)
      cout << ((a / def + 1) * def - a) << endl;
    else
      cout << ((a / def) * def - a) << endl;
  }
}
