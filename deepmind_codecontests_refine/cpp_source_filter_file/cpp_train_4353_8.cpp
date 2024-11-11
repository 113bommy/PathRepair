#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<tuple<string,int,int>> x(n);
  for(int i=0;i<n;i++){
    cin>>get<0>(x.at(i))>>get<1>(x.at(i));
    get<1>(x.at(i))=(-1)*get<1>(x.at(i))
    get<2>(x.at(i))=i+1;
  }
  sort(x.begin(),x.end());
  for(int j=0;j<n;j++)cout<<get<2>(x.at(j))<<endl;
}
