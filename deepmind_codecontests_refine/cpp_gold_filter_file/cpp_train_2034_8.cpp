#include <bits/stdc++.h>
const int INF = (int)1e9 + 7;
using namespace std;
long double n;
int main() {
  cin >> n;
  if (n >= -128 && n <= 127) {
    puts("byte");
    return 0;
  }
  if (n >= -32768 && n <= 32767) {
    puts("short");
    return 0;
  }
  if (n >= -2147483648 && n <= 2147483647) {
    puts("int");
    return 0;
  }
  if (n >= -9223372036854775808 && n <= 9223372036854775807) {
    puts("long");
    return 0;
  }
  puts("BigInteger");
  return 0;
}
