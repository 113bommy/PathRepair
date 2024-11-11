#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int c;
    cin >> c;
    cout << c - 1 << "\n";
    for (int i = 0; i < c - 1; i++) cout << i + 1 << " ";
  }
}
