#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, r, sall, sk;
  cin >> n >> k >> l >> r >> sall >> sk;
  int arr[n];
  for (int i = 0; i < (n); i++) arr[i] = l;
  int sum = l * n;
  int index = 0;
  while (sum < sall) {
    arr[index++ % n]++;
    sum++;
  }
  int ksum = 0;
  for (int i = 0; i < (k); i++) ksum += arr[i];
  while (ksum < sk) {
    int addto = 0;
    while (arr[addto] == r) addto++;
    arr[addto]++;
    int sub = n - 1;
    while (arr[sub] == 0) sub--;
    arr[sub]--;
    ksum++;
  }
  for (int i = 0; i < (n); i++) cout << arr[i] << " ";
  return 0;
}
