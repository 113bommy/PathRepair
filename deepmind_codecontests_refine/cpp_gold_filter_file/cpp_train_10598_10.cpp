#include<bits/stdc++.h>
using namespace std;

int main(){
int r,x,D;
  cin>>r>>D>>x;
  for(int i=0;i<10;i++){
    x=r*x-D;
    cout<<x<<endl;
  }
}