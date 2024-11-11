#include <iostream>
using namespace std;

int main(){
  int N, a;
  bool is_odd = false;
  cin >> N;
  for(int i = 0; i < N; i++){
  	cin >> a;
    if(a % 2 == 1) is_odd = true;
  }
  cout << (is_odd ? "first" : "second") << endl;
  return 0;
}
