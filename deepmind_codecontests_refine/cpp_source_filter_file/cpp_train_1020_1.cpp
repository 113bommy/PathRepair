#include <iostream> 
using namespace std;
typedef long long int ll;
int sum = 0,n;
void dfs(ll x,int a,int b,int c) {
    if (x > n) return;
    if (a & b & c) sum++;
    dfs(x * 10 + 3, 1, b, c);
    dfs(x * 10 + 5, a, 1, c,);
    dfs(x * 10 + 7, a, b, 1);
}
int main() {
    cin >> n;
    dfs(0, 0,0,0);
    cout << sum << endl;
}