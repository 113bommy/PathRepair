#include <bits/stdc++.h>
using namespace std;
long long modulo(long long base, long long exp, long long m);
int main() {
  int x;
  cin >> x;
  if (x <= 1)
    cout << "-1";
  else {
    cout << x - 1 << " " << x - 1;
  }
  return 0;
}
long long modulo(long long base, long long exp, long long m) {
  long long answer = 1;
  while (exp > 0) {
    if (exp % 2 == 1) answer = (answer * base) % m;
    exp = exp / 2;
    base = (base * base) % m;
  }
  return answer;
}
