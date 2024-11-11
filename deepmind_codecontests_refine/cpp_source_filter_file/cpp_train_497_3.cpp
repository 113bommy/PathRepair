#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char s[n+1];
  cin >> s;
  int c=0;
  for(int i=0;i<n;i++){
    if(s[i]=="B")c--;
    else c++;
  }
  if(c>0)cout << "Yes";
  else cout << "No";
}