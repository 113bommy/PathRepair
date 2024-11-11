#include <iostream>
#include  <algorithm>
#include <string>
#incude  <vector>
using namespace atd;
 int main()
{
string s;cin>>s;
int c=0,a=0;

for(int i=2;i<s.size()-1;i++){
if (s[i]=='C'){c++;}
}
for(int i=1;i<s.size();i++){
if (s[i]=='C'){c++;}
else if (islower (s[i])){a++;}
}
if (c==2&&s[0]=='A'&&a==s.size()-2){cout<<"AC";}
else{cout<<"WA";}
return 0;
}
