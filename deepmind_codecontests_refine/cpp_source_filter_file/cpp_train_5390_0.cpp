#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,r=0;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='R') r++;
    }
  int c=0;
  for(int i=0;i<r;i++)
    if(s[i]=='W') c++;
    }
cout<<c;
  
  return 0;
  }