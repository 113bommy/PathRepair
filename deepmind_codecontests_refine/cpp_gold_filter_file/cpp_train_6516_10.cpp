#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string a = "aabb";
  for (long long i = 0; i < n; i++) {
    cout << a[i % 4];
  }
  cout << endl;
  return 0;
}
