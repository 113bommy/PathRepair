#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  string s;
  cin >> n >> s;
  vector<int> c(26,1);
  long long ans=1;
  for(int i=0;i<n;i++){
    c[s[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    ans*=c[i];
    ans%=1000000007;
  }
  cout << (ans-1)%1000000007 << endl;
}