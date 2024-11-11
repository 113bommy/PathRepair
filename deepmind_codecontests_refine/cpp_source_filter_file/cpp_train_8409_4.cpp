#include <bits/stdc++.h>
using namespace std;
bool isprime(int k){
    for(int i=1;i*i<=x;i++){
        if(k%i==0)return false;
    }
    return true;
}
int main() {
long long x;
cin >> x;
for(int j=x;j<10000000;j++){
    if(isprime(j)){cout <<j;
    break;}
}
}
