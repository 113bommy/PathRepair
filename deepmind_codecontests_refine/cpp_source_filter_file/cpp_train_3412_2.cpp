#include<iostream>
using namespace std;
int main() {
  int K;
  cin >> K;
  int i;
  int a = 7;
  for(i=0;i<K;i++) {
    if(a % K == 0) {
      cout << i+1 << endl;
      return ;
    }
    a = (a*10+7)%K;
  }
  cout << -1 << endl;
}