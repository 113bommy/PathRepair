#include <bits/stdc++.h>
using namespace std;
long long n, a, s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s += i * a;
  }
  cout << s << endl;
  return 0;
}
