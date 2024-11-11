#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b=1;
    cin>>a;
    for(int i=2;i<=a;i++){
        b*=i;
        b=b%1000000007;
    }
    cout<<b<<endl;
}