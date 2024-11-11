#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
  string s;
  int n;
  cin>>n>>s;
  puts(n%2==0&&s.substr(0,n/2)==s.substr(n/2,n/2)?"Yes":"No");
}