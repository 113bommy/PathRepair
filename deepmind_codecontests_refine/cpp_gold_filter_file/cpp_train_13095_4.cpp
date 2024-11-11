#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int m=n;
  for(int i=0; i<n-1; i++){
    if(s[i]==s[i+1]) m--;
  }
  cout << m << endl;
}