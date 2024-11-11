#include<bits/stdc++.h>
using namespace std;

enum COMPARE {LESS, EQUAL, MORE};

struct Rational {long unsigned int numerator, denominator;};
bool operator<(const Rational& lhs, const Rational& rhs) {return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;}
bool operator!=(const Rational& lhs, const Rational& rhs) {return lhs.numerator * rhs.denominator != rhs.numerator * lhs.denominator;}

ostream& operator<<(ostream& os, const Rational& r) {
  cout << r.numerator << "/" << r.denominator;
  return os;
}

struct BinaryTree {
  unique_ptr<BinaryTree> left_child, right_child;
  BinaryTree() : left_child(nullptr), right_child(nullptr) {}
};

string traverse(const BinaryTree& node) {
  if(!node.left_child) return "x";
  return "(" + traverse(*node.left_child) + " " + traverse(*node.right_child) + ")";
}

BinaryTree parse(const string& list, int& index) {
  BinaryTree result;
  if(list[index] == '(') {
    result.left_child = unique_ptr<BinaryTree>(new BinaryTree(parse(list, ++index)));
    result.right_child = unique_ptr<BinaryTree>(new BinaryTree(parse(list, ++index)));
  }
  ++index;
  return result;
}

string sort(const BinaryTree& node) {
  if(!node.left_child) return "x";
  auto left = sort(*node.left_child);
  auto right = sort(*node.right_child);
  if(left < right) swap(left, right);
  return "(" + left + " " + right + ")";
}

set<string> structure(const BinaryTree& node) {
  set<string> result({sort(node)});
  if(node.left_child) {
    auto left = structure(*node.left_child);
    auto right = structure(*node.right_child);
    result.insert(begin(left), end(left));
    result.insert(begin(right), end(right));
  }
  return result;
}

Rational similarity(const BinaryTree& node) {
  if(!node.left_child) return Rational({0, 1});
  set<string> left = structure(*node.left_child);
  set<string> right = structure(*node.right_child);
  vector<string> intersection(left.size() + right.size());
  auto it = set_intersection(begin(left), end(left), begin(right), end(right), begin(intersection));
  intersection.resize(it - begin(intersection));
  return Rational({intersection.size(), left.size() + right.size() - intersection.size()});
}

COMPARE compare(const BinaryTree& lhs, const BinaryTree& rhs) {
  auto left = similarity(lhs);
  auto right = similarity(rhs);
  if(left != right) return left < right ? MORE : LESS;
  if(!lhs.left_child) return EQUAL;
  auto compare_lhs = compare(*lhs.left_child, *lhs.right_child);
  auto compare_rhs = compare(*rhs.left_child, *rhs.right_child);
  auto high = compare(
    (compare_lhs == MORE ? *lhs.left_child : *lhs.right_child),
    (compare_rhs == MORE ? *rhs.left_child : *rhs.right_child)
  );
  if(high != EQUAL) return high;
  return compare(
    (compare_lhs == LESS ? *lhs.left_child : *lhs.right_child),
    (compare_rhs == LESS ? *rhs.left_child : *rhs.right_child)
  );
}

void arrange(BinaryTree& node, bool left = true) {
  if(node.left_child) {
    auto order = compare(*node.left_child, *node.right_child);
    if(left && order == LESS) swap(node.left_child, node.right_child);
    if(!left && order == MORE) swap(node.left_child, node.right_child);
    arrange(*node.left_child, true);
    arrange(*node.right_child, false);
  }
}

int main() {
  string list;
  while(getline(cin, list), list != "0") {
    int index = 0;
    BinaryTree root = parse(list, index);
    arrange(root);
    cout << traverse(root) << endl;
  }
}