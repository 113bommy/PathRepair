#include<iostream>
using namespace std;
int main(){
char g[42]={97,102,107,112,117,122,98,103,108,113,118,46,99,104,109,114,119,63,100,105,110,115,120,33,101,106,111,116,121,32};
string s,a;
while(cin>>s,!cin.eof()){
a="";
for(int i=0;i<s.size();i+=2){
int l=s[i]-'0',r=s[i+1]-'0';
if(s.size()%2||l<1||r<1||l>6||r>5){a="NA";break;}
a+=g[r*6+l-7];
}
cout<<a<<endl;
}	
}