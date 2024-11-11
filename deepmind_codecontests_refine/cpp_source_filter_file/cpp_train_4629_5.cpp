#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long g, h, l;
const int N = 100005;
int arr[N];
int main() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  if (n % 2) {
    cout << 5 << " * " << 4 << " = "
         << " " << 20 << endl;
    for (int i = 6; i <= n; i += 2) {
      cout << i + 1 << " - " << i << " = "
           << " " << 1 << endl;
    }
    int temp = n - 5;
    temp /= 2;
    while (temp) {
      cout << 1 << " * " << 1 << " = "
           << " " << 1 << endl;
    }
    cout << 2 << " - " << 1 << " = "
         << " " << 1 << endl;
    cout << 3 << " + " << 1 << " = "
         << " " << 4 << endl;
    cout << 20 << " + " << 1 << " = "
         << " " << 4 << endl;
  } else {
    for (int i = 5; i <= n; i += 2) {
      cout << i + 1 << " - " << i << " = "
           << " " << 1 << endl;
    }
    int temp = n - 4;
    temp /= 2;
    while (temp--) {
      cout << 1 << " * " << 1 << " = "
           << " " << 1 << endl;
    }
    cout << 4 << " * " << 3 << " = "
         << " " << 12 << endl;
    cout << 12 << " * " << 2 << " = "
         << " " << 24 << endl;
    cout << 24 << " * " << 1 << " = "
         << " " << 24 << endl;
  }
}
