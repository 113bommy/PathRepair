#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a,b,k;
  cin >>a>>b>>k;
  for (int i=a;i<=b;i++) {
	if (i<=a+k-1 || i>=b-k+1) {
	  cout << i << endl;
	}
  }
}