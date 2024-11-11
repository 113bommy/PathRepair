#include<bits/stdc++.h>
using namespace std;
int main(){long long A,B,N,x;cin>>A>>B>>N;
           if(N<B)x=(A*N)/B;else x=A*(B-1)/B;
           cout<<x<<endl;