#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int last = n % 10;
    if (last)
      last -= 1;
    else
      last /= 10;
  }
  cout << n << endl;
}
