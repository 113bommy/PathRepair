#include <bits/stdc++.h>
using namespace std;
 
int main(){
int a,b,e,f;
  cin>>a>>b;
  vector<int> d(b,0);
  for(int i=0;i<a;i++){
    cin>>e;
for(int j=0;j<e;j++){
  cin>>f;
  d.at(f-1)++;
}
  }
  int k=0;
  for(int i=0;i<b;i++){
    if(d.at(i)==a)
      k++;
  }
  cout<<k<<endl;
}