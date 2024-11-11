#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  int P[N];
  for(int i=0;i<N;i++)cin>>P[i];
  set<int> s;
   for(int i=0;i<k;i++)s.insert(P[i]);
  int ans=1;
  for(int i=0;i<N-K;i++) {
    if(P[i]==*s.begin() and P[i+K]>*s.rbegin())ans--;  
    // cerr<<*s.begin()<<" "<<*s.rbegin()<<endl;
    ans++;
    s.erase(P[i]);
    s.insert(P[i+K]);
  }    //相交区间   单调队列 
  int a=0,b=1;
 for(int i=1;i<N;i++)
  {
    if(P[i-1]<P[i])b++;
    else b=1;
    if(b==K)a++;
  }  
  ans-=max(a-1,0);    //不相交区间 
  cout<<ans<<endl;
  return 0;
}
