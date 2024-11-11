#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    b++;
    for(int i=a;i<min(a+c,b);i++) cout<<i<<endl;
    for(int i=max(a+c,b-c);i<b;i++) cout<<i<<endl;
}

