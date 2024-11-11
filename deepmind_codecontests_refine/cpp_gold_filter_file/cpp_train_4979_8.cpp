#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  cout << (a + b == 15 ? '+' : a * b == 15 ? '*' : 'x');
}