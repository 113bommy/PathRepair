#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N; cin >> N;
    int A[200010];
    for(int i=0; i<N; ++i){
        cin >> A[i];
        A[i] -= i+1;
    }
    sort(A, A+N);
    int P=N/2
    long S=0;
    for(int i=0; i<N; ++i) S += abs(A[i]-A[P]);
    cout << S << endl;
}