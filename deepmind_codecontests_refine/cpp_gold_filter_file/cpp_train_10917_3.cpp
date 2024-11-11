#include <iostream>
using namespace std;
 
int gcd(int a, int b) {
return a % b ? gcd(b, a % b) : b;
}
int lcm(int a, int b) {
return a / gcd(a,b) * b;
}
 
int main() {
int a, b;
while(cin >> a >> b) {
cout << gcd(a,b) << " " << lcm(a,b) << endl;
}
}