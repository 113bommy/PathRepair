#include <iostream>
#include <string>
using namespace std;
bool p(string v){int n = v.size();for(int i=0;i<n;i++){if(v[i]!=v[n-1-i])return false;}return true;}
int main(){string s;cin>>s;int n=s.size();string a=s.substr(0,n/2),b=s.substr(n/2+1,n);if(p(s)&&p(a)&&p(b))puts("Yes");else puts("No");}
