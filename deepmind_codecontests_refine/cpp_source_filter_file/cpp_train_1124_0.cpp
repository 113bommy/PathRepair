#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<char> t(Q), d(Q);
    for (ll i = 0; i < Q; i++) {
        cin >> t[i] >> d[i];
    }

    //[left, right]にあるものは生き残る
    ll left = 0, right = N - 1;

    for (ll i = Q-1;i>=0;i--) {
        if (d[i] == 'L') {
            if (t[i] == s[left]) {
                left++;
            }
            //範囲を広げている
            if (right < N-1 && t[i] == s[right+1]) {
                right++;
            }
        } else {
            if (t[i] == s[right]) {
                right--;
            }
            //範囲を広げている
            if (left > 0 && t[i] == s[left-1]) {
                left--;
            }
        }
    }

    cout << max(right - left + 1,0) << endl;
}
