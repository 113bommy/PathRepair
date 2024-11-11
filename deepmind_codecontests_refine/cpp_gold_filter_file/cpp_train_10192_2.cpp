#include<iostream>
using namespace std;
int p1, p2, p3, j1, j2;
int main(){
cin >> p1 >> p2 >> p3 >> j1 >> j2;
cout << min(min(p1, p2), p3) + min(j1, j2) - 50 << endl;
return 0;
}