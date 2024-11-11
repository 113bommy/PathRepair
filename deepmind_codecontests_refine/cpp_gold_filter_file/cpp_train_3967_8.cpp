#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m) {
  int size = n / 5;
  size = size + 1;
  int arr1[451];
  int arr2[451];
  for (int i = 0; i < 451; i++) {
    arr1[i] = 5;
    arr2[i] = 4;
  }
  arr2[450] = 5;
  for (int i = 0; i < 451; i++) cout << arr1[i];
  cout << endl;
  for (int i = 0; i < 451; i++) cout << arr2[i];
}
int main() {
  int n, m;
  cin >> n >> m;
  solve(n, m);
}
