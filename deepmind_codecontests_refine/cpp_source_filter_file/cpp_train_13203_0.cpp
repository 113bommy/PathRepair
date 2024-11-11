#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    for(cin>>N;N;--N){
        int t,x,y;
        cin>>t>x>>y;
        if(t<x+y||(t-x-y)&1)return cout<<"No",0;
    }
    return cout<<"Yes",0;
}