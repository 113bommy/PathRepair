#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
cin>>s1>>s2;
reverse(s2.begin(),s2.end());
s1+=s2;
for(int i=0;i<s1.size();i++){
if(i%2)cout<<s[i/2];
else cout<<s[s.size()-1-i/2];
}
}