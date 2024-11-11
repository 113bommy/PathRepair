#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d;
  cin >> n >> d;
  cout << ceil(double(n) / (1 + 2*d)) << endl;
}