#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x=0;
  int y;
  int d=0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    x+=vec.at(i);
  }
y=(double)x/n+0.5
  for(int i=0;i<n;i++){
    d+=(y-vec.at(i))*(y-vec.at(i));
  }
  cout<<y<<endl;
}
    
