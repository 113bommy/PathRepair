#include<iostream>
using namespace std;
int L, A, B, C, D;
int rA = 0, rB = 0;
int main(){
cin >> L >> A >> B >> C >> D;
if( a - (A/C) * C > 0) { rA = 1;}
if( B - (B/D) * D > 0) { rB = 1;}
cout << L - max((A/C) + rA,(B/D) +rB ) << endl;
return0;
}