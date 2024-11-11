#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,b,ans;
  int a;
  cin >> n;
  for(a=1; a<=pow(n,0.5); a++){
    b=n/a;
    if(a*b==n){
      ans=a+b-2;
    }
  }
  cout << ans << endl;
}