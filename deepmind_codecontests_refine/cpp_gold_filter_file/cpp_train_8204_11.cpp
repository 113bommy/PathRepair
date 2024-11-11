#include<iostream>
#include<string>
using namespace std;

int main(){
  int n, ans=0, k;
  string s;
  cin >> n >> s;
  for(int i=1; i<n; i++){
    k=0;
    for(char t='a'; t<='z'; t++)
      if(s.substr(0,i).find(t)!=string::npos && s.substr(i).find(t)!=string::npos)
        k++;
    if(ans<k) ans = k;
  }
  cout << ans << endl;
}
