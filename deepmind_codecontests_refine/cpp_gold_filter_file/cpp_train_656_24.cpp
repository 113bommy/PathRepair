#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  long long int res = 0;
  cin >> n;
  for (long long int i = 0; i < ((long long int)(n)); ++i) {
    long long int a;
    cin >> a;
    res += a * (i + 1);
  }
  cout << res << endl;
}
