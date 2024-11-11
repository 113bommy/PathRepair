#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, persons, validate = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> persons;
    if (persons + k <= 5) {
      validate++;
    }
  }
  cout << validate / 3;
  return 0;
}
