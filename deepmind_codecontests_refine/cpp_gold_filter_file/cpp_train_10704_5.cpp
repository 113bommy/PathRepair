#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans[n];
  for(int i=0;i<n;i++) ans[i]=0;
  for(int i=1;i<n;i++){
    if(s[i]=='E'){
      ans[0]++;
    }
  }
  for(int i=1;i<n;i++){
    ans[i]=ans[i-1];
    if(s[i]=='E'){
      ans[i]--;
    }
    if(s[i-1]=='W'){
      ans[i]++;
    }
  }
  sort(ans,ans+n);
  cout << ans[0] << endl;
}