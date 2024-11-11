#include <bits/stdc++.h>
using namespace std;
int ar[] = {2, 6, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
  int n, a, sum = 1;
  cin >> n;
  for (int i = 0; i < 2; i++) {
    a = n % 10;
    sum *= ar[a];
    n /= 10;
  }
  cout << sum << endl;
  return 0;
}
