#include <bits/stdc++.h>
int main() {
  std::map<std::string, int> users{std::make_pair("polycarp", 1)};
  int n;
  std::string a, b, aaa;
  std::cin >> n;
  while (n-- && std::cin >> a >> aaa >> b)
    users["kurac"] =
        (std::transform(a.begin(), a.end(), a.begin(), ::tolower) !=
             a.begin() &&
         std::transform(b.begin(), b.end(), b.begin(), ::tolower) != b.begin())
            ? ((users.find("kurac") != users.end())
                   ? (((users[a] = users[b] + 1) > users["kurac"])
                          ? users[a]
                          : users["kurac"])
                   : 1)
            : 1;
  std::cout << users["kurac"];
}
