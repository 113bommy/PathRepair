#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string num;
    cin >> num;
    int hum;
    cin >> hum;

    vector<int> used(N);
    int c = 0;
    for (int i = 0; i < N && c < hum; i++) {
        if (num[i] == '0') {
            num[i] = '1';
            c++;
            used[i] = true;
        }
    }

    int j = N-1;
    while (c < hum) {
        if (!used[j]) {
            c++;
            num[j] = '0';
        }
        j--;
    }

    cout << num << endl;

    return 0;
}