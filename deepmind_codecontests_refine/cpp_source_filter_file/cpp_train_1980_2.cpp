#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int fn[50];
  fn[0] = fn[1] = 1;
  for(int i = 2; i <= n; i++) fn[i] = fn[i - 1] + fn[i - 2];
  }
  cout << fn[n] << end;
  
  return 0;
}