#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int y=0;
  for(int i=0;i<25;i++)if(N>=4*i&&(N-4*i)%7==0)y++;
  if(y)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
