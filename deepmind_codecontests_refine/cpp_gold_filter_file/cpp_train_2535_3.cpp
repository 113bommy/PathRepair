#include <bits/stdc++.h>
using namespace std;
vector<int> raices;
void raiz(long long n) {
  for (int i = 2; i < n; i++) {
    raices.push_back(i * i);
  }
}
long long bun(int n) {
  if (n == 0) {
    return 0;
  }
  return (2 * bun(n - 1) + 2);
}
long long paty(int n) {
  if (n == 0) {
    return 1;
  }
  return (2 * (paty(n - 1)) + 1);
}
bool puede(string a, string b) {
  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[j]) {
      j++;
      if (j == b.size()) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  cout << n << " ";
  for (int i = 1; i < n; i++) {
    cout << i << " ";
  }
}
