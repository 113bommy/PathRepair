#include <bits/stdc++.h>
using namespace std;
using L = long long;
#define F first
#define S second
#define I XH[i]
using V= pair<L,L>;

L N,D,A,now=0,res=0,t;
V XH[200005];
queue<V>P;
int main() {cin>>N>>D>>A;for(L i=0;i<N;i++){cin>>I.F>>I.S;}sort(XH,XH+N);for(L i=0;i<N;i++){while(!P.empty()&&P.front().F<I.F){now-=P.front().S;P.pop();}I.S-=now;if(I.S>0){t=(I.S+A-1)/A;res+=t;P.push({I.F+2*D,t*A});now+=t*A;}}cout<<res;} 
