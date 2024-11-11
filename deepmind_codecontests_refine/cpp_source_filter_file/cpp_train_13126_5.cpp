#include <bits/stdc++.h>
using namespace std;
int A, B;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    A += x;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    B += x;
  }
  if (A <= B) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
