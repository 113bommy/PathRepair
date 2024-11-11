#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  int n;
  cin >> n;
  for (int i = 0; true; i++) {
    a.push_back(n % 2);
    n /= 2;
    if (n == 0) {
      break;
    }
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] == 1) {
      cout << i + 1;
    }
  }
}
