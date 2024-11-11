#incldue <bits/stdc++.h>
using namespace std;
int main(){
char a,b,c;
int n=0;
cin>>a>>b>>c;
if(a=='x')n++;
if(b=='x')n++;
if(c=='x')n++;
cout<<700 + n *100<<endl;
}