#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
cin>>s1>>s2;
reverse(s1.begin(),s1.end());
s1=s2+s1;
for(int i=0;i<s1.size();i++){
if(i%2)cout<<s1[i/2];
else cout<<s1[s1.size()-1-i/2];
}
}