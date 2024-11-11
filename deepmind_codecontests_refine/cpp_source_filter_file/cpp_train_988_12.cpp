#include <bits/stdc++.h>
using namespace std;
int main() {
  long long X = 0, Y = 0;
  long long n, b;
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    int carry;
    cin >> carry;
    X += carry * pow(b, n - i - 1);
  }
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    int carry;
    cin >> carry;
    Y += carry * pow(b, n - i - 1);
  }
  if (X > Y)
    puts(">");
  else if (X < Y)
    puts("<");
  else
    puts("=");
  return 0;
}
