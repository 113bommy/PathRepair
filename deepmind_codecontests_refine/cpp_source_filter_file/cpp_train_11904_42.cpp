#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int S, a, b, c;
  cin >> S >> a >> b >> c;
  if (a + b + c == 0) {
    printf("%lf %lf %lf\n", double(S), 0.0, 0.0);
  } else {
    printf("%lf %lf %lf\n", double(a) * double(S) / double(a + b + c),
           double(b) * double(S) / double(a + b + c),
           double(c) * double(S) / double(a + b + c));
  }
  return 0;
}
