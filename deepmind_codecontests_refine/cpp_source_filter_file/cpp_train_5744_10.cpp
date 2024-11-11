#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
int arr[N];
int arr2[N];
char a[N];
int find(int n) {
  for (int i = n; i <= 1000; i++) {
    int sum = 0;
    int res = i;
    while (res > 0) {
      sum += res % 10;
      res /= 10;
    }
    if (sum % 4 == 0) {
      return i;
      return 0;
    }
  }
}
int main() {
  int n;
  cin >> n;
  cout << find(n) << endl;
}
