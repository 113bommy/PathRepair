#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0, sum = 0; cin >> n;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    m = max(x, m);
    sum+=x;
  }
  cout << ((sum-me>m ? "Yes" : "No"));
}

