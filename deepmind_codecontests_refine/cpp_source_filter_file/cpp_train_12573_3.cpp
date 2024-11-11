#include<bits/stdc++.h>
#define R(n)for(L i=0;i<n;i++)
#define M make_pair
typedef __int64 L;using namespace std;int main(){L n,k,s,t,a[50];cin>>n>>k>>s>>t;R(n)cin>>a[i];map<pair<L,L>,L> p[50];R(n){for(L j=k-1;j;j--)for(auto&l:p[j-1])p[j][M(l.first.first&a[i],l.first.second|a[i])]+=l.second;p[0][M(a[i],a[i])]=1;}n=0;R(k)n+=p[i][M(s,t)];cout<<n;}