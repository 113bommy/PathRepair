#include <bits/stdc++.h>
using namespace std;
int h;
long long n, des;
long long GetRes(long long l) {
  if (l == 1) return 0;
  if ((l + l / 2) % 2) {
    return 1 + GetRes(l / 2);
  } else {
    return pow(2, h - (int)(log2(l)) + 1) + GetRes(l / 2);
  }
}
int main() {
  while (cin >> h >> n) {
    des = pow(2, h) - 1 + n;
    cout << GetRes(des) << endl;
  }
  return 0;
}
