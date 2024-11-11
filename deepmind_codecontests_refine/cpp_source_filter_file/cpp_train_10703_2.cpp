#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;con>>N;
  int ans=0;
  for(int i=0;i<4;i++){
    if(N%10==2)ans++;
    N=(N-N%10)/10;
  }
  cout<<ans<<endl;
}
