#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,k;
  cin >> a >> b >> k;
  for(int i=1;i<=k;i++){
    if(i%2==1){
      b+=a/2;
      a/=2;
    }
    else{
      a+=b/2;
      b/=2;
    }
  }
  cout << a << " " << b << endl;
}