#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int main(){
int a;
string str;
cin>>a;
set<string> S;
for (int i=0;i<a;i++){
cin>>str;
S.insert(str);}
cout<<S.size()<<endl;
