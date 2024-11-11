#include<iostream>
namespace std;

int main(){
	int a;
  cin >> a;
  a = a%10;
  if(a == 2 || a == 4 || a == 5 || a == 7 || a == 9) cout << "hon";
  else if (a == 3) cout << "bon";
  else cout << "pon";
}