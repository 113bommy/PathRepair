#include <bits/stdc++.h>
using namespace std;
bool marked[1000001];
bool perfect_square(long long int in) { return (sqrt(in) == floor(sqrt(in))); }
int main() {
  for (long long int i = 2; i < 100001; i++) {
    if (marked[i] == false) {
      for (long long int j = 2; (i * j) <= 100001; j++) {
        marked[i * j] = true;
      }
    }
  }
  long long int n, x;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1)
      cout << "NO" << endl;
    else {
      if (perfect_square(x)) {
        long long int t = sqrt(x);
        if (marked[t] == false)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else
        cout << "NO" << endl;
    }
  }
}
