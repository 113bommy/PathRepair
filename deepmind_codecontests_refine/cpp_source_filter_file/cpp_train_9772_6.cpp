#include<iostream>
#include<string>
using namespace std;
int main(){
int a,u=0;l=0,d=0,r=0;
string s;
cin >> s;
for(int i=0;i<(int)s.size();i++){
if(s[i]=='N')u=1;
if(s[i]=='E')r=1;
if(s[i]=='W')l=1;
if(s[i]=='S')d=1;
}
if(u==d && r==l)cout << "Yes" << endl;
else cout << "No" << endl;
return 0;
}