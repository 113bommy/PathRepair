#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> k;
    arr[k-1]=i+1;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}