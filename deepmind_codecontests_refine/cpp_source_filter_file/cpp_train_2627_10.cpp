#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, p;
  cin >> a;
  long long int s = 0;
  for (int i = 1; i <= a; i++) {
    cin >> p;
    if (p >= 0) {
      s += p;
      cout << s << " ";
    } else
      cout << s << " ";
  }
}
