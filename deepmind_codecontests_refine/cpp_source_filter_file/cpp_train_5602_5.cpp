#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  cout << max(a+b, 2a-1, 2b-1)<< endl;
}
