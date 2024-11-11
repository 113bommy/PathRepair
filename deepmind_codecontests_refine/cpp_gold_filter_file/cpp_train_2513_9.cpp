#include <bits/stdc++.h>
using namespace std;
int n, a;
string m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    if (m[i] == '0' or m[i] == '2' or m[i] == '4' or m[i] == '6' or
        m[i] == '8') {
      a += i + 1;
    }
  }
  cout << a;
}
