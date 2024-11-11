#include <isotream>

using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  
  if(C >= A && B <= C) cout << "Yes";
  else cout << "No";

}