#include <bits/stdc++.h>
using namespace std;
int ar[200];
int main() {
  int n;
  cin >> n;
  int k = 0;
  if (n & 1) {
    n -= 3;
    k++;
    k += n / 2;
    cout << k << endl;
    for (int i = 0; i < n / 2; i++) {
      cout << 2 << " ";
    }
    cout << 3 << endl;
  } else {
    k += n / 2;
    cout << k << endl;
    for (int i = 0; i < n / 2; i++) {
      cout << 2 << " ";
    }
  }
}
