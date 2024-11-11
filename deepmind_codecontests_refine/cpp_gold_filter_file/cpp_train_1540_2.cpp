#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  int sum = 0;
  for(int i=0,x;i<m;cin>>x,sum+=x,i++);
  if(sum>n)cout<<-1<<endl;
  else cout<< n-sum<<endl;
}
