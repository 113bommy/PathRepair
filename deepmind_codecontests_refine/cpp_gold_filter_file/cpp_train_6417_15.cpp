#include <bits/stdc++.h>
using namespace std;
int arr[10005]{};
int main() {
  int a = 1;
  for (int i = 15; a < 10005; ++i) {
    int sum = 0;
    int num = i;
    while (num > 0) {
      sum += num % 10;
      num = num / 10;
    }
    if (sum == 10) {
      arr[a] = i;
      ++a;
    }
  }
  int n;
  cin >> n;
  cout << arr[n] << " \n";
  return 0;
}
