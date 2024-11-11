#include <bits/stdc++.h>
using namespace std;
long long x[1000005];
int main() {
  long long n, tot = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] % 2 != 0) {
      tot++;
    }
  }
  if (tot % 2 == 0) {
    cout << "Second";
  } else {
    cout << "First";
  }
}
