#include <bits/stdc++.h>
using namespace std;
unordered_set<int> s;
int main() {
int n; cin >> n;
for (int i = 0; i < n; i++) {
int a; cin >> a;
auto it = s.find(a);
if (it != s.end()) {
s.erase(a);
} else {
s.insert(a);
}
}
std::cout << s.size() << "\n";
}