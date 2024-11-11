#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, a, b;
  cin >> n >> a >> b;
  if (b > 0) {
    int temp = abs(b) % n;
    while (temp--) {
      if (a == n)
        a = 1;
      else
        a++;
    }
    cout << a;
  } else if (b < 0) {
    int temp = abs(b) % n;
    while (temp--) {
      if (a == 1)
        a = n;
      else
        a--;
    }
    cout << a;
  } else {
    cout << a;
  }
}
