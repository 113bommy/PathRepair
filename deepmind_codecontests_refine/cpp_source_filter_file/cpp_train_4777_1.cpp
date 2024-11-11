#include<iostream>
using namespace std;
int main() {
int s,a,d,c;
while(cin>>a>>d,a)) {
s=a+d;c=0;
for(int i=1;i<5;i++) {
cin>>a>>d;
if(s<a+d)s=a+d,c=i;
}
cout<<(char)(c+'A')<<' '<<s<<endl;
}
}