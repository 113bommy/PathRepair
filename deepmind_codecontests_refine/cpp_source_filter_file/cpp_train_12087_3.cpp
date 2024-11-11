#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int n[k];
  for (int i = 0; i < k; i++) {
    cin >> n[i];
    if (n[i] == 0) {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
}
