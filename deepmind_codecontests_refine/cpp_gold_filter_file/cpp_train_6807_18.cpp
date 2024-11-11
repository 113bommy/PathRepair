#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000 + 7;
const double esp = 1e-13;
const double pi = 3.141592653589;
int n;
int main() {
  cin >> n;
  if (n % 2 == 0)
    cout << -1;
  else {
    for (int i = (0), _b = (n); i < _b; i++) cout << i << " ";
    cout << "\n";
    for (int i = (0), _b = (n); i < _b; i++) cout << i << " ";
    cout << "\n";
    for (int i = (0), _b = (n); i < _b; i++) cout << 2 * i % n << " ";
  }
}
