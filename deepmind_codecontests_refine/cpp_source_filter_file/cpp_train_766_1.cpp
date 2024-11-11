#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0;
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  int arr[n];
  for (int i = 0; i <= n - 1; i++) {
    cin >> arr[i];
    if (arr[i] < 0) {
      a++;
      v1.push_back(arr[i]);
    }
    if (arr[i] > 0) {
      b++;
      v2.push_back(arr[i]);
    }
    if (arr[i] == 0) c++;
  }
  if (a % 2 != 0 && b > 0) {
    cout << a << " ";
    for (int j = 0; j <= a - 1; j++) cout << v1[j] << " ";
    cout << "\n";
    cout << b << " ";
    for (int k = 0; k <= b - 1; k++) cout << v2[k] << " ";
    cout << "\n";
    cout << c << " ";
    for (int g = 1; g <= c; g++) cout << 0 << " ";
  }
  if (a % 2 != 0 && b == 0) {
    cout << a - 2 << " ";
    for (int p = 0; p <= a - 3; p++) cout << v1[p] << " ";
    cout << "\n";
    cout << 2 << " ";
    cout << v1[a - 2] << " " << v1[a - 1] << "\n";
    cout << c << " ";
    for (int d = 1; d <= c; d++) cout << 0 << " ";
  }
  if (a % 2 == 0 && b > 0) {
    cout << a - 1 << " ";
    for (int x = 0; x <= a - 2; x++) cout << v1[x] << " ";
    cout << "\n";
    cout << b << " ";
    for (int f = 0; f <= b - 1; f++) cout << v2[f] << " ";
    cout << "\n";
    cout << c + 1 << " " << v1[a - 1] << " ";
    for (int s = 1; s <= c; s++) cout << 0 << " ";
  }
  if (a % 2 == 0 && b == 0) {
    cout << a - 3 << " ";
    for (int h = 0; h <= a - 4; h++) cout << v1[h] << " ";
    cout << "\n";
    cout << 2 << " " << v1[a - 3] << " " << v1[a - 2] << "\n";
    cout << c + 1 << " " << v1[a - 1] << " ";
    for (int w = 0; w <= c; w++) cout << 0 << " ";
  }
}
