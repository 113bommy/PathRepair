#include <iostream>
#include <algorithm>
using namespace std;
int a[15];

int main(){
    for(int i=0;i<10;i++) cin >> a[i];
    sort(a,a+10);
    cout << a[9] << endl << a[8] << endl << a[7] << endl;
    return 0;
}
