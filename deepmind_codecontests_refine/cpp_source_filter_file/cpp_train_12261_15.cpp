#include<bits/stdc++.h>
using namespace std;
int main(){int x=0,y=0;char t;for(int i=0;i<3;i++){cin>>t;
if(t=='R'&&x==y){y++;x++;}else y=0;}cout<<x<<endl;