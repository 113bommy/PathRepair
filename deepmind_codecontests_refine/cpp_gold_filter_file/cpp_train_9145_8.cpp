#include <bits/stdc++.h>
using namespace std;
int main () {
  int K, T;
  cin >> K >> T;
  int a, m = 0;
  for(int i = 0; i < T; i++){
    cin >> a;
    m = max(m, a);
  }
  if(m - 1 <= K - m)cout << 0 << endl;
  else cout << m - 1 - K + m; 
  return 0;
}