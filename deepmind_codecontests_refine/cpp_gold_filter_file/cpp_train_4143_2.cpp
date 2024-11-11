#include<bits/stdc++.h>
using namespace std;

int main()
{
  long N;
  cin>>N;
  long ans=1;
  while(ans<=N){
    ans*=2;
  }
  cout<<ans-1<<endl;
}