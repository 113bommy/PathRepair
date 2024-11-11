#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
  map<string,int> data;
int i;
int N;
cin>>N;
string a[N];
for(i=0;i<N;i++){
cin>>a[i]; 
data[a[i]]++;}
  int M;
cin>>M;
string b[M];
for(i=0;i<M;i++){
cin>>b[i];
  data[b[i]]--;
}  
  int ans=0;
  for(auto itr:data){
  int res=max(ans,itr.second);}
  cout<<res;
}
  