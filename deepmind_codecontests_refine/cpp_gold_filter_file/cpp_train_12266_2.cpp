#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  while(b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x;
  cin >> n >> x;
  int g = 0;
  while(n--) {
    int y;
    cin >> y;
    g = gcd(abs(x - y), g);
  }
  cout << g << '\n';
}

