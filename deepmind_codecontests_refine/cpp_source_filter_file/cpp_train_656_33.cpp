#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  int a0;
  int a;
  cin >> a0;
  int64_t output = 0;
  for (int i = 0; i < a0; ++i) {
    cin >> a;
    output += a * a;
  }
  std::cout << output << std::endl;
  return 0;
}
