#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
string s, pre, post;
cin>>s;pre = s.at(0), post ="";
int k = 0;
for(int i = 1; i<s.size(), i++){
post += s[i];
if(pre!=post){
k++;
pre = post;
post = "";
}


} 
cout<<k<<endl;
}
