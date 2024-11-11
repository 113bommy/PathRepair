#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    cout << 4 << ' ' << n - 2 << endl;
  } else {
    cout << 9 << ' ' << n - 9 << endl;
  }
}
