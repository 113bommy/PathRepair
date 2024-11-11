#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string a = "abccab";
  for (long long i = 0; i < n; i++) {
    cout << a[i % 6];
  }
  cout << endl;
  return 0;
}
