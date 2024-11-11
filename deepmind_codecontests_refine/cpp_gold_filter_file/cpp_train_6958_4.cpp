#include<bits/stdc++.h>//头文件
using namespace std;
long long q,h,s,d,n;
int main(){
    cin>>q>>h>>s>>d>>n;
    cout<<(n%2==0?min(min(min(q*8,h*4),s*2),d)*n/2:min(min(q*4,h*2),s)+min(min(min(q*8,h*4),s*2),d)*(n-1)/2);
}