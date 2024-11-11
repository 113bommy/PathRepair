#include<bits/stdc++h>
using namespace std;
int main(){int N,K,d,x;cin>>N>>K;vector<int>a(N,1);x=N;
   for(int i=0;i<K;i++){cin>>d;for(int j=0;j<d;j++){cin>>b;if(a.at(b-1)){a.at(b-1)=0;x--;}}}
           cout<<x<<endl;}