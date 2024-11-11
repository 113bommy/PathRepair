#include<bits/stdc++.h>
using namespace std;

int main(){
 string a;
  cin>>a;
  int c,d;
  c=0;
  d=a.size()
  for(int i=0;i<d;i++){
    if(i%2==0&&a[i]=='0'){
c++;
  }
    if(i%2==1&&a[i]=='1'){
      c++;
    }
  }
  c=min(c,d-c);
       cout<<c<<endl;
}
