#include <iostream>
using namespace std;
int main(){int A,B,C,X,Y,p;cin >> A >> B >> C >> X >> Y;
cout << min(min(A*X+B*Y,2*C*min(X,Y)+ ((X - Y) > 0 ? A * (X - Y) : B * (Y - X))),2 * C * ((X - Y) > 0 ? X : Y));
}