#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  for(long long a = 1;a <= 500; a++) {
    for(long long b = a-1; b>= -a+1; b--) {
      if(pow(a,5) - pow(b,5) == X) {
        cout << a << " " << b << endl;
        break;
      }
    }
  }
}