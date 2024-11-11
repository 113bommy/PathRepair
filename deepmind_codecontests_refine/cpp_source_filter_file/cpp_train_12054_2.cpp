#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,sum=0;
  cin>>a;
  for(int i=1;i<=a;i++) if(i%5!=0 && i%3!=0) ans+=i;
  cout<<ans<<endl;
}