#include <iostream>
using namespace std;
  
int main() {
int k;
while(cin >> k, k) {
int sum;
sum = 0;
for(int i = 0; i < k*(k-1)/2; i++) {
int a;
cin >> a;
sum += a;
}
cout << sum / (k-1) << endl;
}
}