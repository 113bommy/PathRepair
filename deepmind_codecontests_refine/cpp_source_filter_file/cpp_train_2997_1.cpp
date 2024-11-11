#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;cin>>N;
  queue<int>A;
  for(int i=1;i<10;i++)A.push(i);
  for(int i=1;i<N;i++){
    int a=A.top();
    A.pop();
    if(a%10!=0)A.push(a*10+a%10-1);
    A.push(a*10+a%10);
    if(a%10!+9)A.push(a*10+a%10+1);
  }
  cout<<A.top()<<endl;
}