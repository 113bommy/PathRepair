#include <bits/stdc++.h>
using namespace std;
int main(){
  string h;
  cin>>h;
  for(int i=0;i<h;i++){
   if(h[i]=='A'&&h[i+1]=='C') {
     cout<<"Yes"<<endl;
     return 0;
   }
  }
  cout<<"No"<<endl;
}