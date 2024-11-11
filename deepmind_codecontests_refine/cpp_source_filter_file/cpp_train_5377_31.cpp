#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n, sum1 = 1;
  cin >> n;
  for (int i = 2; i <= n / 2; i++) {
    if ((n - i) % 2 == 0) sum1++;
  }
  cout << sum1 << endl;
}
