#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
if(s.find("A")<s.rfind("Z"))
{
cout<<(s.rfind("Z")-s.find("A"))+1;
}
else
cout<<0;
}