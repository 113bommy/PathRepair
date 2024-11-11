#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  map<int,int> m;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    if(m.count(x)){
      m.at(x)++;
    }else{
      m[x]=0;
    }
  }
  
  int sum=0;
  for(auto i:m){
    sum+=i.second
  }
  
  cout<<sum/2+sum%2<<endl;
}
  