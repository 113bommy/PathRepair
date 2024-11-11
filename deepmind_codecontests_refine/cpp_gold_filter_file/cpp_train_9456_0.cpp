#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
  string s;
  char op[3];
  int n[4],sum;
  cin>>s;
  rep(i,4){
    n[i]=s[i]-'0';
  }
  rep(i,(1<<3)){
    sum=n[0];
    rep(j,3){
      if(i&(1<<j)){
        op[j]='-';
        sum-=n[j+1];
      }else{
        op[j]='+';
        sum+=n[j+1];
      }
    }
    if(sum==7){
      break;
    }
  }
  cout<<n[0];
  rep(i,3){
    cout<<op[i]<<n[i+1];
  }
  cout<<"=7"<<endl;
}

