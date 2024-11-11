#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int W[N];
  for(int i=0;i<N;i++;) cin>>W[i];
  int b=0;
  for(int i=0;i<N;i++) b+=W[i];
  int a=0;
  int ans=b;
  for(int i=0;i<N-1;i++){
    a+=W[i];
    b-=W[i];
    int c=abs(a-b);
    ans=min(ans,c);
  }
  cout<<ans<<endl;
    
}
