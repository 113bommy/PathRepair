#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int total=0;
  int d=0;
  vector<int>vec(n);
  for (int i=0;i<n;i++){
cin>>vec.at(i);
    total+=vec.at(i);
  }
  int y=(double)total/n+0.5;
  for (int i=0;i<n;i++){
    d+=(y-vec.at(i))*(y-vec.at(i));
  }
  cout<<d<<endl;
}
