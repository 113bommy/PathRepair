#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, r = 0, c = 1;
  cin >> n >> x;
  if(int i = 0; i < n; i++){
    int p;
    cin >> p;
    r += p;
    if(r <= x)
      c++;
  }
  cout << c << endl;
}