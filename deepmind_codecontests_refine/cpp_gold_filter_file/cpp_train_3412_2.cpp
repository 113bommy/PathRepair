#include <bits/stdc++.h>
using namespace std;

int main(){
  int k,u=0;
  cin >> k;
  for(int i=1;i<=k;i++){
    u=(u*10+7)%k;
    if(u%k==0){
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
