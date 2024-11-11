#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,i;
  b = 100;
  i = 0;
  cin >> a;
  while(b < a){
    b = b * 1.01;
    i++;
  }
  cout << i;
}