#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char s[n];
  for(int i=0;i<n;i++){
    cin >> s[i];
    if(s[i]=='Y'){
      cout << "Four";
      return 0;
    }
  }
  cout << "Three";
}
