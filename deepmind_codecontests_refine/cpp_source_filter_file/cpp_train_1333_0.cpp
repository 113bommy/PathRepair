#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int a[5], ans=0, res=0;
  for(int i=0; i<5; i++){
  cin >> a[i];
  ans+=10*ceil(a[i]/10);
  if(res<10*ceil(a[i]/10)-a[i])
    res=10*ceil(a[i]/10)-a[i];
  

  cout << ans-res;
  return 0;
}
