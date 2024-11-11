#include <iostream>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int L,R,l = -1,R = 1000000001;
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    
    L = max(L,l);
    R = min(R,r);
  }
  if(R-L + 1 < 0)cout << 0;
  else cout << R - L + 1;
}
    