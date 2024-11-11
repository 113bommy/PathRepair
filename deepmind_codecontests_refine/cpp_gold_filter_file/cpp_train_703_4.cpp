#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N,M;
  bool s=false;
  cin>>N>>M;
  vector<int> a={1,0,0};
  vector<bool> b(3,false);
  for(int i=0;i<M;i++){
    int A,B;
    cin>>A>>B;
    if(!b[A-1]){a[A-1]=B;b[A-1]=true;}
    if(b[A-1]&&a[A-1]!=B){cout<<-1;s=true;break;}
    if(N!=1&&a[0]==0){cout<<-1;s=true;break;}
  }
  if(!s&&N==3){cout<<a[0]<<a[1]<<a[2];}
  else if(!s&&N==2){cout<<a[0]<<a[1];}
  else if(!s&&N==1&&M==0){cout<<0;}
  else if(!s&&N==1){cout<<a[0];}
}