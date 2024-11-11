#include <bits/stdc++.h>
int main(int argc, char* argv[]) {
  int n, a, b;
  std::cin >> n >> a >> b;
  printf("%d\n", std::min(n - a, b + 1));
}
