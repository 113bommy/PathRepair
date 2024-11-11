#include<iostream>
using namespace std;
int main(){
  int s[4] = {},a,b;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  cin >> a >> b;s[a-1]++;s[b-1]++;
  if(a[0]!=3 && a[1]!=3 && a[2]!=3 && a[3]!=3) cout << "YES" << endl;
  else cout << "NO" << endl;
}