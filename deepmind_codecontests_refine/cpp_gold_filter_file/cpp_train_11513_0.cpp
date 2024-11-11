#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int i = 0;
  while (n--) {
    char a = (i % k) + 97;
    cout << a;
    i++;
  }
}
