#include<iostream>
#include<set>
using namespace std;

int main() {
    int N, A_i, k, i;

    cin >> N;
    set<int> B;

    for(i=0; i<N; i++) {
        cin >> A_i;
        B.insert(A_i);
    }

    k = B.size();

    if(k%2 == 1) {
        cout << k << endl;
    }
    else {
        cout << k-1 << endl;
    }
    
    return 0;
}