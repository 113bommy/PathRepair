#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,s=1000000;
  cin>>n;
  for(int i=0; i<n; i++){
    int a,b=0;
    cin>>a;
    while(a%2==0){
      a/=2;
      b+=1;
    }
    if(s>b){
      s = b;
    }
  }
  cout<<s;
}