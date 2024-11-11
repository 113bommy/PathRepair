#include <iostream>
using namespace???std;
int main(){
  int a[]={5,7,5,7,7},n,i,j,c,k;
  while(cin>>n,n){
    string s[n];
    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<n;i++){
      c=k=0;
      for(j=i;j<n;j++){
        c+=s[j].size();
        if(c==a[k]){
          c=0;
          if(++k==5)goto L:
        }
      }
    }
    L: if(k==5)cout<<i<<endl;
  }
}