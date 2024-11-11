#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n > 1) {
    n--;
    n *= 2;
    cout << n << " " << 2 << endl << 1 << " " << 2 << endl;
  } else
    cout << n << " " << 1 << endl << 1 << " " << 1 << endl;
}
