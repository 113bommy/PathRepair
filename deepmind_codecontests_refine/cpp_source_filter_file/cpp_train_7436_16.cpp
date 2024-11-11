#include <bits/stdc++.h>
using namespace std;
void toLeft(int n, string slogan) {
  for (int i = n - 1; i >= 0; i--) {
    cout << "PRINT " << slogan[i] << "\n";
    if (i) cout << "LEFT\n";
  }
}
void toRight(int n, string slogan) {
  for (int i = 0; i < n; i++) {
    cout << "PRINT " << slogan[i] << "\n";
    if (i != n - 1) cout << "RIGHT\n";
  }
}
int main() {
  int n, k;
  string slogan;
  cin >> n >> k >> slogan;
  if (n == k)
    toLeft(n, slogan);
  else if (k == 1)
    toRight(n, slogan);
  else if (k > n / 2) {
    for (int i = 0; i < n - k; i++) cout << "RIGHT\n";
    toLeft(n, slogan);
  } else {
    for (int i = 0; i < k; i++) cout << "LEFT\n";
    toRight(n, slogan);
  }
}
