#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int N, c=0, ns;
string n, s;
cin>>N>>n;
ns = n.length();
while (N--){
string s;
cin>>s;
if ([&](){
for (int i=0;i<s.length();++i)
if(s[i] == n[0])
for(int p=1;;++p){
if(i+p*(ns-1)>= s.length())break;
for(int h=1;h<ns;h++)
if(s[i+p*h]!=n[h])break;
else if (h==ns-1return true;
}
return false;
}()
)c++;
}
cout << c << endl;
}