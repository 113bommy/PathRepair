#include <bits/stdc++.h>
using namespace std;
int N;
int a[200200];
int main() {
  cin >> N;
  if (N % 4 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      a[i] = 2 * i + 1;
      a[i + N] = 2 * i + 2;
    } else {
      a[i] = 2 * i + 2;
      a[i + N] = 2 * i + 1;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < 2 * N; i++) {
    cout << a[i] << " ";
  }
}
