#include<iostream>
using namespace std;

int main(){
 int n,x,l;
 while(1){
  cin >> n >> x;
  if(n==0&&x==0) break;
  l=0;
  for(int i=1;i<=n-2;++i){
   for(int j=i+1;j<=n-1;++j){
    for(int k=i+2;k<=n;++k){
     if(i+j+k==x) l+=l;
    }
   }
  }
 cout << l << endl;
 return 0;
}