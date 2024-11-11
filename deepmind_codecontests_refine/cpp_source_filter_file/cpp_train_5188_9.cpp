#include<bits/stdc++/h>
using namespace std;
int main(){
  int n;
  string a,t;
  cin>>n;
  t="Three"
  for(int i=0;i<n-1;i++){
    cin>>a;
    if(a=="Y")
      t="Four"
  }
  cout<<t<<endl;
}