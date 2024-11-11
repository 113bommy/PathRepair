#include <iostream>

using namespace std;

int main()
{string s;
int c=0,cc=0,a=0;
cin>>s;
if(s[0]!='A'||s[1]=='C'){cout<<"WA"<<endl;}
else{
for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C'){c++;}

    
}
for(int i=0;i<s.size();i++){
    if(s[i]>96&&s[i]<123){a++;}
}

if((c==0||c>1||(a!=s.size()-2)){cout<<"WA"<<endl;}
else{cout<<"AC"<<endl;}
}
    return 0;
}