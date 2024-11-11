#include<bits/stdc++.h>
using namespace std;
int main(){int N,M;cin>>N>>M;int h[N],v[M],w[M],x=N;vector<int>c(N,1);for(int i=0;i<N;i++)cin>>h[i];
           for(int i=0;i<M;i++){cin>>v[i]>>w[i];if(h[v[i]-1]>=h[w[i]-1]&&c.at(w[i]-1)){c.at(w[i]-1)=0;x--;}
                               if(h[v[i]-1]<=h[w[i]-1]&&c.at(v[i]-1){c.at(v[i]-1)=0;x--;}}cout<<x<<endl;}
           
