#include <bits/stdc++.h>
using namespace std;
long long A[10][10];
long long B[10][10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n > 0) {
    if (n % 4 == 1) {
      cout << 'b';
      n--;
    } else if (n % 4 == 2) {
      cout << 'b';
      n--;
    } else if (n % 4 == 3) {
      cout << 'a';
      n--;
    } else if (n % 4 == 0) {
      cout << 'a';
      n--;
    }
  }
  return 0;
}
