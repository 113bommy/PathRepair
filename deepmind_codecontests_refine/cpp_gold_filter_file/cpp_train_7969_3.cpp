#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  long long int x, y, z, a, b;
  scanf("%lld", &x);
  if (x <= 2)
    printf("-1\n");
  else {
    if (x % 2)
      a = x * x, b = 1;
    else
      a = x * x / 2, b = 2;
    y = (a - b) / 2;
    z = (a + b) / 2;
    printf("%lld %lld\n", y, z);
  }
  return 0;
}
