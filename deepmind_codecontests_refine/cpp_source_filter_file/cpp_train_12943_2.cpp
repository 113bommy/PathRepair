#include <bits/stdc++.h>
using namespace std;
long long xor_of_continuous(long long a, long long b) {
  a--;
  long long tmp = b % 4;
  if (tmp == 0)
    b = b;
  else if (tmp == 1)
    b = 1;
  else if (tmp == 2)
    b = b + 1;
  else
    b = 0;
  tmp = a % 4;
  if (tmp == 0)
    a = a;
  else if (tmp == 1)
    a = 1;
  else if (tmp == 2)
    a = a + 1;
  else
    a = 0;
  return (a ^ b);
}
int main() {
  int n;
  cin >> n;
  long long a, b, ans = 0;
  while (n--) {
    cin >> a >> b;
    ans = (ans ^ xor_of_continuous(a, a + b));
  }
  if (ans == 0)
    cout << "bolik" << endl;
  else
    cout << "tolik" << endl;
}
