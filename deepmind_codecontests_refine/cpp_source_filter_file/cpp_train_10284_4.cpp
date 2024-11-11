#include<iostream>
using namespace std;

int main(void){
    int K, A, B;
    cin >> K >> A >> B;
    cout << (B/K - (A-1)/K > 0)? "OK" : "NG") << endl;
    return 0;
}