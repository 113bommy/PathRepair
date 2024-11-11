#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;cin >> n;
  string S="APPROVED";
  for (int i=0;i<n;i++) {
    long long a;cin >> a;
	if (a%2==0 && (a%3)*(a%5)>0) S="DENIED";
  }
  cout << S << endl;
}
