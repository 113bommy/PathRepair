#include<iostream>
using namespace std;

int main(void){
  int n;
  cin >> n;
  for (int x = 0; x <= n; x += 4) {
    if ((n - x) % 7 == 0){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
