include<iostream>
#include<stdio.h>

using namespace std;

int a[15];
int main(){
    for(int i=0; i<4; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    cout << ( (a[1]&&a[9])&&(a[7]&&a[4]) ? "YES" : "NO") << endl;
    return 0;
}
