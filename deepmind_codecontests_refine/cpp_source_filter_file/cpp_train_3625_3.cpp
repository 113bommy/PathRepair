#include <iostream>
 
using namespace std;
 
int main()
{
string s;
cin>>s;
int a=0 , b=0 , c=0 ;
if (s[0] == 'A'){
    x++;
}
for (int i = 2 ; i < s.size()-1 ; i++){
    if (s[i]=='C')
        y++;
}
for (int i=0 ;i <s.size(); i++){
    if(s[i]>=65&&s[i]==90){
        z++;
    }
}
if(x==1 && y==1 && z==2)
    cout<<"AC";
else
    cout<<"WA";
 
 
}