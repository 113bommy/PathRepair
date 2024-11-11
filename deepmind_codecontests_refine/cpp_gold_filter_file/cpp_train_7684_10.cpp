#include<iostream>
using namespace std;

int main(){
  int a, b, ans;
  cin >> a >> b;
  ans = (b-a)*(b-a+1)/2-b;
  cout << ans << endl;
}
