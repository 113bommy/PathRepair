#include<bits/stdc++.h>
using namespace std;
using l = long;

l main(){
    l a,e,y,x,n,N;cin >> N;n=0;e=0;
    map<l,l> w;
    for(l i=0;i<N;i++){cin>>a;w[a]=i;}
    
    multiset<l> S;
    vector<l> d={-1,-1,N,N};
    for(l i=0;i<4;i++)S.insert(d[i]);

    for(l i=N;i>=1;i--){
        l k=w[i];
        S.insert(k);
        auto t=S.lower_bound(k),p=t,q=t,r=t,s=t;
        p--;p--;q--;r++;s++;s++;

        n+=(*q-*p)*(*r-k)+(k-*q)*(*s-*r);
        e+=n;
    }

    cout<<e<<endl;
}
