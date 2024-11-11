#include<bits/stdc++.h>
using namespace std ;
int main () {
  long long  N , A , B ;
  cin >> N >> A >> B ;
  long long ans = 0 ;
  if(A>B) ans = 0 ;
  else ans =max(0,(N-2)*(B-A)+1) ;
  cout << ans << endl ;
}
