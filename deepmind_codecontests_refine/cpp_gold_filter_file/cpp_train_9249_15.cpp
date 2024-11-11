#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b; char c; cin >> a >> c >> b;
  cout << a + (c == '+' ? b : -b) << endl;
}
