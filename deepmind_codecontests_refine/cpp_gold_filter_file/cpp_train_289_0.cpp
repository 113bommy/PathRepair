#include<bits/stdc++.h>
using namespace std;int main(){string s,t="keyence";cin>>s;for(int i=0;i<=7;i++){string a=t.substr(0,i),b=t.substr(i,7-i);if(a==s.substr(0,i)&&b==s.substr(s.size()-7+i,7-i)){cout<<"YES";return 0;}}cout<<"NO";}
