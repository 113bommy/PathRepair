#include<bits/stdc++.h>
using namespace std;

int main(void){
    int A, B;
    cin >> A  >> B;
    cout << max(max(A+B,A-B),A*B) << endl;
}
