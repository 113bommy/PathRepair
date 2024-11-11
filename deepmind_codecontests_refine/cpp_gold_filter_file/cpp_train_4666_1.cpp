#include<iostream>
using namespace std;
int main(){
  int s[4] = {},a,b;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  if(s[0]!=3 && s[1]!=3 && s[2]!=3 && s[3]!=3) cout << "YES" << endl;
  else cout << "NO" << endl;
}
