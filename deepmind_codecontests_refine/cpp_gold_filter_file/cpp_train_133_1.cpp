#include <bits/stdc++.h>
using namespace std;
long long t, k = 1;
bool check(long long a) {
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return 0;
  return 1;
}
int init(long long a) {
  for (int i = 2; i <= a / 2; i++)
    if (a % i == 0) {
      if (check(a / i) == 0) {
        t = a / i;
        k = i;
        return 1;
      } else
        return 0;
    }
}
int ini(long long a, int k) {
  for (int i = 2; i <= a / 2; i++)
    if (a % i == 0) {
      k *= i;
      return k;
    }
  return 0;
}
int main() {
  long long a;
  cin >> a;
  if (check(a) == 1) {
    cout << "1" << endl;
    cout << "0" << endl;
  } else if (init(a) == 0)
    cout << "2" << endl;
  else if (init(a) == 1) {
    cout << "1" << endl;
    cout << ini(t, k) << endl;
  }
}
