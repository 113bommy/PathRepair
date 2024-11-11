z#include<bits/stdc++.h>

int main(){
    using namespace std;
    string S;
    cin >> S;
    size_t K;
    cin >> K;
    for(const auto c : S)if(!(c == '1' && --K))return 0 & putchar(c);
    return 0;
}