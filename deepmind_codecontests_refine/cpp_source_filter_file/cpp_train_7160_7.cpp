#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int n=S.size()-1;
  puts(S.substr(0,n/2)==S.substr(n\2+1)?"Yes":"No");
}