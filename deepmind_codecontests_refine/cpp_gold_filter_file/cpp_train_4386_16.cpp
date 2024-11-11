#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  char ch[200000];
  cin >> n >> ch;
  for (i = 0; i < n - 1; i++) {
    if (ch[i] > ch[i + 1]) break;
  }
  if (i == n) i = n - 1;
  for (int j = 0; j < n; j++) {
    if (i != j) printf("%c", ch[j]);
  }
  cout << endl;
  return 0;
}
