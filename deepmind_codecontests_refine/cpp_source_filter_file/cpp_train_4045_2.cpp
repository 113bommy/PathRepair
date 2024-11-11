#include <iostream>
using namespace std;
int main(){
int code[256]={0};
char st[30];
bool diff=true;
cin >> st;
for(int i=0;i<30;i++){
if(st[i]==0)break;
code[st[i]]++;
if (code[st[i]]>1)diff=false;
}
cout<<diff?"yes":"no"<<endl;
return 0;}