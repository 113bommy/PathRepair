#inculde <iostream>
#include <algorithm>
using namespace std;
string s;
int main(){
  cin>>s;
  int n=s.size()-8;
  for(int i=0;i<n;i++)cout<<s[i];
}