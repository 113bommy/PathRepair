#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  char a, b, A, B;
  int maxx = 0, counter = 0;
  for (int i = 0; i < n - 1; i++) {
    a = s[i];
    b = s[i + 1];
    counter = 1;
    for (int j = i + 1; j < n - 1; j++) {
      if (a == s[j] && a == s[j + 1]) {
        counter++;
      }
      if (maxx < counter) {
        A = a;
        B = b;
        maxx = counter;
      }
    }
  }
  cout << A << B;
  return 0;
}
