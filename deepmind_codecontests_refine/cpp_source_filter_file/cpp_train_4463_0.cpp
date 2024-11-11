#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(a,a%b);
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=abs(a-c),y=abs(b-d);
    cout<<((x/gcd(x,y))+(y/gcd(x,y))-1)*gcd(x,y)
    return 0;
}
