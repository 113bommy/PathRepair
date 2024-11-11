#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>>N;
  int ans=0;
  while(true){
    for(int i=1;i<N;i++){
      if(N%i==0)ans++;
    }
    if(ans==1){
      cout<<N<<endl;
      break;
    }
    ans=0;
    N++;
  }
}
