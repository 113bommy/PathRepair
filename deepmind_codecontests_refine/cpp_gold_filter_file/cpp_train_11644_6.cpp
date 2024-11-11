#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M;cin>>N>>M;
    cout<<((N-M)*100+1900*M)*pow(2,M)<<endl;
}