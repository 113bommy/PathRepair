#include <bits/stdc++.h>
using namespace std;
int main(){
char a,b,c;
int n=0;
cin>>a>>b>>c;
if(a=='o')n++;
if(b=='o')n++;
if(c=='o')n++;
cout<<700 + n *100<<endl;
}