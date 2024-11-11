#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  cout<<regex_replace(s,regex(",")," ")<<endl;