#include <bits/stdc++.h>
int X[50], Y[50];
int n;
std::string to_string(int x) {
  if (x == 0) return std::string("0");
  std::string ret;
  while (x) {
    ret.push_back(x % 10 + '0');
    x /= 10;
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}
std::string work(int *X, int l, int r) {
  if (l == r) {
    return "(" + to_string(X[l] / 2) + "*((1-abs((t-" + to_string(l) +
           ")))+abs((abs((t-" + to_string(l) + "))-1))))";
  }
  int mid = l + r >> 1;
  return "(" + work(X, l, mid) + "+" + work(X, mid + 1, r) + ")";
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%*d", X + i, Y + i);
  }
  std::cout << work(X, 0, n - 1) << std::endl;
  std::cout << work(Y, 0, n - 1) << std::endl;
}
