#include<iostream>
#include<vector>
using namespace std;
int main(){
  long long x,i;
  cin >> x;
  for(i=x;x<=i*(i+1)/2;i--);
  cout << i+1 << endl;
}
