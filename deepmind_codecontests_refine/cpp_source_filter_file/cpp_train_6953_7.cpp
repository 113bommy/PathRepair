#include <bits/stdc++.h>
int main() {
  using namespace std;
  unsigned long N;
  cin >> N;
  for (unsigned long i{1}; i < 10; ++i)
    if (N & i == 0 && N / i <= 9) return 0 & puts("Yes");
  puts("No");
  return 0;
}
