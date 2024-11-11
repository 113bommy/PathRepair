#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  char a;
  int ans=0;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
      cin>>a;
      if(a=='#')
        ans++;
    }
  if(ans==h+w-1)
    cout<<"Possible";
  else cout<<"Impossible";
  
}