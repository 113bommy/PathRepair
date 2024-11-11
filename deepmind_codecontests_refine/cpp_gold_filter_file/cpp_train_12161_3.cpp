#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  for(int i=0;i<m;i++) cin>>b.at(i);
  int cnt=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<m;j++){
      int k;
      cin>>k;
      sum+=b.at(j)*k;
    }
    if(sum+c>0) cnt++;
  }
  cout<<cnt<<endl;
}
