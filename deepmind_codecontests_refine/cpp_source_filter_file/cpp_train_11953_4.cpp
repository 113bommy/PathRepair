#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string a[3];
  cin>>a[0]>>a[1]>>[2];
  int ans=0;
  for(int i=0;i<n;i++){
    set<char> s;
    for(int j=0;j<3;j++){
      s.insert(a[j].at(i));
    }
    ans+=s.size()-1;
  }
  cout<<ans<<endl;
}