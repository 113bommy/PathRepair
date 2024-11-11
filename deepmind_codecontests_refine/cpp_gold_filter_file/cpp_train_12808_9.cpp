#include <iostream>
using namespace std;

int main(void){

    int a, i=1;

    while (cin >> a, a != 0)
        cout << "Case " << i++ << ": "<< a << endl;
}