#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  int n, d;
  std::cin >> n >> d;
  int max = 0, current = 0;
  for (int i = 0; i < d; i++) {
    std::string s;
    std::cin >> s;
    if (s.find("0") != std::string::npos)
      current++;
    else
      current = 0;
    if (max < current) max = current;
  }
  std::cout << max << std::endl;
}
