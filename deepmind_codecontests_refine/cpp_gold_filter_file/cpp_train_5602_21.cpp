#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  cout << max({a+b,a+a-1,b+b-1}) << endl;
}