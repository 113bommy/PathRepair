#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>>N;
  int ans=2;
  while(true){
    for(int i=1;i<N;i++){
      if(N%i=0)ans--;
    }
    if(ans=0){
      cout<<N<<endl;
      break;
    }
    ans=2;
    N++;
  }
}