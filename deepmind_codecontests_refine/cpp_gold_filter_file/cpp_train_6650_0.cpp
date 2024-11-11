#include <iostream>
using namespace std;
 
void gcd(int a, int b, int step);
 
int main()
{
    int a, b;
 
    while (cin >> a >> b, a){
        gcd(a, b, 0);
    }
 
    return (0);
}
 
void gcd(int a, int b, int step)
{
    if (b == 0){
        cout << a << " " << step << endl;
    }
    else if (a < b){
        return (gcd(a, b % a, step + 1));
    }
    else {
        return (gcd(b, a % b, step + 1));
    }
}