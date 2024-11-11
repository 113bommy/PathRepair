#include<iostream>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  cout << (b>=c-a&&c>=a ? "YES" : "NO") << endl;
}