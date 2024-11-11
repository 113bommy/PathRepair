#include<bits/stdc++.h>
using namespace std;
int main(){int N,K,m=1;cin>>N>>K;for(int i=0;i<N;i++){if(m<K)m*=2;else {m+=(N-i)*K;break;}cout<<m<<endl;} red