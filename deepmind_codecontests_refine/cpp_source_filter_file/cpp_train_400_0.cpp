#include <bits/stdc++.h>
using namespace std;
string s[]={"afkpuz","bglqv.","chmrw?","dinsx!","ejoty "};
int main(){string ss;while(cin>>ss){
if(ss.size()%2==1){cout<<"NA"<<endl;continue;}
bool b=1;string ans="";for(int i=0;i<ss.size()-1;i+=2){
if(!('1'<=ss[i+1]&&ss[i+1]<='5')||!('1'<=ss[i]&&ss[i]<='6')){b=0; break;}
ans+=s[in[i+1]-'0'-1][in[i]-'0'-1];}
if(b)cout<<ans<<endl;else cout<<"NA"<<endl;
}}