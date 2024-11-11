#include<iostream>
using namespace std;
int main(){
  int n,p[20];
  int a,b,c;
  
  cin>>n;
  for(int i=0;i<n;i++)cin>>p[i];
  for(int i=1;i<n-1;i++){
    if(p[i-1]>p[i]&&p[i]<p[i+1]){
      cnt++;
    }else if(p[i-1]<p[i]&&p[i]>p[i+1]){
      cnt++;
    }
  }
  cout<<cnt<<endl;
}