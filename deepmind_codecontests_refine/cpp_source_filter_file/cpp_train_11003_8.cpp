#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int arr[] = {1, 5, 20, 100};
  long long int res = 0;
  for (int i = 3; i >= 0; i--) {
    res = res + (n / arr[i]);
    n = n % arr[i];
  }
  cout << res;
}
