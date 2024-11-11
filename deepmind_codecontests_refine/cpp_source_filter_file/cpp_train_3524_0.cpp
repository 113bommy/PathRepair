#include <iostream>
int N;
int main(){
long long p = 1;
std::cin >> N;
for(int i = 1; i <= N; ++i) sum = sum * i % 1000000007;
std::cout << sum << std::endl;
}