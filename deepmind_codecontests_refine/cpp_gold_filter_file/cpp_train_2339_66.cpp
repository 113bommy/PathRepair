#include <bits/stdc++.h>
using namespace std;
int main() {
  string uncle;
  string cat;
  string dog;
  cin >> uncle;
  cin >> cat;
  cin >> dog;
  if (uncle == "rock" && cat == "rock" && dog == "rock") {
    cout << "?";
  } else if (uncle == "rock" && cat == "rock" && dog == "paper") {
    cout << "S";
  } else if (uncle == "rock" && cat == "rock" && dog == "scissors") {
    cout << "?";
  } else if (uncle == "rock" && cat == "paper" && dog == "rock") {
    cout << "M";
  } else if (uncle == "rock" && cat == "paper" && dog == "paper") {
    cout << "?";
  } else if (uncle == "rock" && cat == "paper" && dog == "scissors") {
    cout << "?";
  } else if (uncle == "rock" && cat == "scissors" && dog == "rock") {
    cout << "?";
  } else if (uncle == "rock" && cat == "scissors" && dog == "paper") {
    cout << "?";
  } else if (uncle == "rock" && cat == "scissors" && dog == "scissors") {
    cout << "F";
  } else if (uncle == "paper" && cat == "rock" && dog == "rock") {
    cout << "F";
  } else if (uncle == "paper" && cat == "rock" && dog == "paper") {
    cout << "?";
  } else if (uncle == "paper" && cat == "rock" && dog == "scissors") {
    cout << "?";
  } else if (uncle == "paper" && cat == "paper" && dog == "rock") {
    cout << "?";
  } else if (uncle == "paper" && cat == "paper" && dog == "paper") {
    cout << "?";
  } else if (uncle == "paper" && cat == "paper" && dog == "scissors") {
    cout << "S";
  } else if (uncle == "paper" && cat == "scissors" && dog == "rock") {
    cout << "?";
  } else if (uncle == "paper" && cat == "scissors" && dog == "paper") {
    cout << "M";
  } else if (uncle == "paper" && cat == "scissors" && dog == "scissors") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "rock" && dog == "rock") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "rock" && dog == "paper") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "rock" && dog == "scissors") {
    cout << "M";
  } else if (uncle == "scissors" && cat == "paper" && dog == "rock") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "paper" && dog == "paper") {
    cout << "F";
  } else if (uncle == "scissors" && cat == "paper" && dog == "scissors") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "scissors" && dog == "rock") {
    cout << "S";
  } else if (uncle == "scissors" && cat == "scissors" && dog == "paper") {
    cout << "?";
  } else if (uncle == "scissors" && cat == "scissors" && dog == "scissors") {
    cout << "?";
  }
}
