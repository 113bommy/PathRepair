#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y;
  cin >> x >> y;
  long long int arr[x];
  for (int i = 0; i < x; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i <= (y / 2); i++) {
    long long int temp = arr[i];
    arr[i] = arr[y - i];
    arr[y - i] = temp;
  }
  for (int i; i < x; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
