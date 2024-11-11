#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (a[i] > a[j]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}
int main() {
  string s;
  cin >> s;
  string revert = s;
  int len = s.length();
  for (int i = 0; i < len / 2; i++) {
    char c = revert[0];
    revert[0] = revert[len - i - 1];
    revert[len - i - 1] = c;
  }
  s = s.append(revert);
  cout << s;
  char c;
  cin >> c;
  return 0;
}
