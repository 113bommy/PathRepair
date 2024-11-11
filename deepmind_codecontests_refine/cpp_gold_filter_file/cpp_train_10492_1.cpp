#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
  int f=0;
if(s.size()%2){cout<<"No";return 0;}
else{
for(int i=0;i<s.size();i+=2){if(s[i]!='h'|| s[i+1]!='i'){f=1;cout<<"No";break;}}
    }
if (f==0)cout<<"Yes";

}