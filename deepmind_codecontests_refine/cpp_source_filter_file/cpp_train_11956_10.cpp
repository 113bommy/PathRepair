#include <iostream>
using namespace std;
int main(){
  int n;k;cin>>n>>k;
  int ans = 0;
  for(int i = 0; n > i; i++){
    int tmp;cin>>tmp;
    ans += min(tmp,k-tmp)*2;
  }
  cout << ans << endl;
}
