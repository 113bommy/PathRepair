#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  cin >> n;
  int arr[7];
  for (int i = 0; i < 7; i++) cin >> arr[i];
  int t = arr[0];
  while (t < n) {
    i++;
    i = i % 7;
    t = t + arr[i];
  }
  cout << i + 1;
}
