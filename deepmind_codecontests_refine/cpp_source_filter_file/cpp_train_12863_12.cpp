#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
int arr[maxn];
int arr1[maxn];
int main() {
  int a, b;
  int k = 0;
  cin >> a >> b;
  while (k * a % 10 != b && (k * a) % 10 != 0) {
    k++;
  }
  cout << k;
}
