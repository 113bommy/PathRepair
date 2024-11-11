#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int arr[1000];
int minn(int a, int b) {
  if (a < b) return a;
  return b;
}
int maxx(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 3 << endl;
    cout << "2 1 2" << endl;
    return 0;
  }
  if (n == 3) {
    cout << 4 << endl;
    cout << "2 1 3 2" << endl;
    return 0;
  } else {
    if (n & 1)
      cout << (n / 2) * 3 + 1 << endl;
    else
      cout << (n / 2) * 3 << endl;
    for (int i = 1; i <= n; i++) {
      if (n % 2 == 0) cout << i << " ";
    }
    for (int i = 1; i <= n; i++) {
      if (n & 1) cout << i << " ";
    }
    for (int i = 1; i <= n; i++) {
      if (n % 2 == 0) cout << i << " ";
    }
  }
}
