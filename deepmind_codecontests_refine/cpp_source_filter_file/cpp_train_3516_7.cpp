#include <iostream>
using namespace std;
int a[200006];
int main () {
    int N, sum=0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a[i];
        sum^=a[i];
    }
    for (int i=0; i<N; i++) {
        cout << sum^a[i] << endl;
    }
}