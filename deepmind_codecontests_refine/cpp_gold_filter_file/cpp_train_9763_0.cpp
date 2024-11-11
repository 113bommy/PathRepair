#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,n;
  cin>>a>>b>>c>>n;
  if(a>=n){
    cout<<n;
  }else if(a+b>=n){
    cout<<a;
  }else{
    cout<<a-(n-(a+b));
  }
}
