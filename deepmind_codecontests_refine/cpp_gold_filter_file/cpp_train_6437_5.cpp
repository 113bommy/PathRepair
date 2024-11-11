#include <bits/stdc++.h>
using namespace std;int main(){string S;cin>>S;int N=S.size(),m=N,i;for(i=1;i<N;++i)if(S[i-1]!=S[i])m=min(m, max(i,N-i));cout<<m<<endl;}
