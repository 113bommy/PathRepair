#include <iostream>
using namespace std;
int N;
int main(){
  cin >> N;
  bool judge = false;
  for(int i=0;i<=25;i++){
	if((N-4*i)%7==0 && N>=4*i) judge = true;
  }
  cout << (judge? "Yes":"No") << endl;
}