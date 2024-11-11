#include<bits/stdc++.h> 
using namespace std;int main(){l n,k;cin>>n>>k;unordered_set<int> g;for(int i=0;i<k;i++){int d;cin>>d;for(int i=0;i<d;i++){int u;cin>>u;g.insert(u);}}int r=g.size();cout<<n-r<<endl;}
