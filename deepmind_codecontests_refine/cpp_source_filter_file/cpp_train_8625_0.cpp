#include<iostream>
#include<string>
using namespace std;
string s;
int p;
int main() {
cin>>s;
for(int i=0;i<s.length;i++){
if(s[i]=='p') p++;
}
cout <<s.length/2-p<<endl;
return 0;
}