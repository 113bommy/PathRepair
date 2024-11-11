#include<bits/stdc++.h>
using namespace std;
int main(){int A,B,c;cin>>A>>B;
           c=B/100-A/100
if(A%100>A/1000%10*10+A/10000)c--;
if(B%100>=B/1000%10*10+B/10000)c++;
 cout<<c<<endl;}