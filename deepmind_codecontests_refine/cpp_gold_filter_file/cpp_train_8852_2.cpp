#include<bits/stdc++.h>
using namespace std;

int main(){
string w;
string t;
int al=0;
cin>>w;
while(cin>>t){
for(int i=0;i<t.size();i++){
if(isupper(t[i])){t[i]=tolower(t[i]);}
}

if(t==w){
al++;
}}

cout<<al<<endl;
return 0;
}
