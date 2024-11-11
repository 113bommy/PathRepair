#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  char c;
  set<char> s;
  for(int i=0;i<n;i++){
    cin>>c;
    s.insert(c);
  }
  cout<<(s.size()==3?"Three":"Four");
}
