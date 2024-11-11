#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  int check[2];
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i], check[arr[i] % 2]++;
  if (check[0] && check[1]) sort(arr, arr + n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
