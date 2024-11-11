#include<iostream>
using namespace std;
int main(){
int x, y;
char op;
for (int i = 0; ; i++){
cin >> x >> op >> y;
if (op=='+') cout << x+y << endl;
else if (op=='-') cout << x-y << endl;
else if (op=='*') cout << x*y << endl;
else if (op=='/') cout << x/y << endl;
else if (op=='?') break;
}
}