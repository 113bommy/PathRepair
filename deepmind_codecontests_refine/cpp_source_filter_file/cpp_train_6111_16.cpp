#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int n[a], m[b];
  for (int i = 0; i < a; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> m[i];
  }
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++) {
      if (n[i] == m[j]) {
        cout << n[j] << " ";
      }
    }
  cout << "\n";
  return 0;
}
