#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  n = (n-1) / 111 + 1;
  cout << n * 111 << endl;
}