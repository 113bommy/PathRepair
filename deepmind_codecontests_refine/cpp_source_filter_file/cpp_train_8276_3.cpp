#include <bits/stdc++.h>
std::string leading_zero(int value, int s_length) {
  std::string answer{std::to_string(value)};
  return std::string(s_length - answer.length(), '0') + answer;
}
int main() {
  std::string time;
  int a{0};
  std::cin >> time >> a;
  int pos = time.find(':');
  auto hours = std::stoi(time.substr(0, pos));
  auto minutes = std::stoi(time.substr(pos + 1, std::string::npos));
  int elapsed_minutes = minutes + a;
  while (elapsed_minutes > 60 && (elapsed_minutes - 60) > 0) {
    hours++;
    elapsed_minutes -= 60;
  }
  while (hours >= 24) {
    hours -= 24;
  }
  std::string hours_str = leading_zero(hours, 2);
  std::string minutes_str = leading_zero(elapsed_minutes, 2);
  std::cout << hours_str << ':' << minutes_str << std::endl;
  return 0;
}
