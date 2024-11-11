#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

const string s = "01235789"

int main(){
  int n;
  while(cin >> n, n){
    stringstream ss;
    while(n){
      ss << s[n % 8];
      n /= 8;
    }
    string ans = ss.str();
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}