#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define INF 100000000
using namespace std;

int main() {
 
int N,a,b,ans=0;
cin >>N;
// vector<int> A(N);
  cin>>a;
  ans+=a;
 for(int i=1; i<N-1; i++){cin>>b; ans+=min(a,b); a=b;}
cout<<ans+a<<endl;
}
