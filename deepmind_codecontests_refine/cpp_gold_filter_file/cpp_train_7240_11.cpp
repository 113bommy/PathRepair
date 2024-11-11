#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int n[a];
  cin >> n[0];
  for (int i = 1; i < a; i++) {
    cin >> n[i];
    cout << n[i - 1] + n[i] << ' ';
  }
  cout << n[a - 1];
}
