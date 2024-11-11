#include <bits/stdc++.h>
using namespace std;
int a[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
int b,c;

int main(){
  cin>>b>>c;
  if(a[b] == a[c]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}