#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  stack<int>s[n];
  while(q--){
    int a,b,c;
    cin>>a>>b;
    if(!a){
      cin>>c;
      s[b].push(c);
    }
    else if(a==1){
      if(!s[b].empty())cout<<s[b].front()<<endl;
    }
    else if(!s[b].empty())s[b].pop();
  }
}
