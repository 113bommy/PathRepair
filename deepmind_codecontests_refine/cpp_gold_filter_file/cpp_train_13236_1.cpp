#include <bits/stdc++.h>
using namespace std;
namespace fastExpress {
template <typename T>
inline T read() {
  T f = 1, x = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print_char(T x, char ch) {
  write(x), putchar(ch);
}
template <typename T>
inline void char_print(char ch, T x) {
  putchar(ch);
  write(x);
}
template <typename T>
inline void print_space(T x) {
  print_char(x, ' ');
}
template <typename T>
inline void space_print(T x) {
  char_print(' ', x);
}
template <typename T>
inline void println(T x) {
  print_char(x, '\n');
}
template <typename T>
inline void lnprint(T x) {
  char_print('\n', x);
}
template <typename T>
inline void print_array_in_range1(T* a, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) print_char(a[i], " \n"[i == r]);
}
template <typename T>
inline void print_array_in_range2(T* a, int l, int r) {
  println(r - l + 1), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range3(T* a, int l, int r) {
  for (int(i) = (r); (i) >= (l); --(i)) print_char(a[i], " \n"[i == l]);
}
template <typename T>
inline void print_array_in_range4(T* a, int l, int r) {
  println(r - l + 1), print_array_in_range3(a, l, r);
}
template <typename T>
inline void print_array_in_range5(T* a, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) println(a[i]);
}
template <typename T>
inline void print_array_in_range6(T* a, int l, int r) {
  println(r - l + 1), print_array_in_range5(a, l, r);
}
template <typename T>
inline void print_array_in_range7(T* a, int l, int r) {
  for (int(i) = (r); (i) >= (l); --(i)) println(a[i]);
}
template <typename T>
inline void print_array_in_range8(T* a, int l, int r) {
  println(r - l + 1), print_array_in_range7(a, l, r);
}
template <typename T>
inline void print_array_in_range9(T* a, int l, int r) {
  print_space(r - l + 1), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range10(T* a, int l, int r) {
  print_space(r - l + 1), print_array_in_range3(a, l, r);
}
template <typename T>
inline void print_array_in_range11(T* a, int l, int r) {
  print_space(r - l + 1), print_array_in_range5(a, l, r);
}
template <typename T>
inline void print_array_in_range12(T* a, int l, int r) {
  print_space(r - l + 1), print_array_in_range7(a, l, r);
}
template <typename T>
inline void print_array_in_range13(T* a, int l, int r, int n) {
  println(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range14(T* a, int l, int r, int n) {
  println(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range15(T* a, int l, int r, int n) {
  println(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range16(T* a, int l, int r, int n) {
  println(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range17(T* a, int l, int r, int n) {
  print_space(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range18(T* a, int l, int r, int n) {
  print_space(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range19(T* a, int l, int r, int n) {
  print_space(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array_in_range20(T* a, int l, int r, int n) {
  print_space(n), print_array_in_range1(a, l, r);
}
template <typename T>
inline void print_array1(T* a, int n) {
  print_array_in_range1(a, 1, n);
}
template <typename T>
inline void print_array2(T* a, int n) {
  println(n), print_array1(a, n);
}
template <typename T>
inline void print_array3(T* a, int n) {
  print_array_in_range3(a, 1, n);
}
template <typename T>
inline void print_array4(T* a, int n) {
  println(n), print_array3(a, n);
}
template <typename T>
inline void print_array5(T* a, int n) {
  print_array_in_range5(a, 1, n);
}
template <typename T>
inline void print_array6(T* a, int n) {
  println(n), print_array5(a, n);
}
template <typename T>
inline void print_array7(T* a, int n) {
  print_array_in_range7(a, 1, n);
}
template <typename T>
inline void print_array8(T* a, int n) {
  println(n), print_array7(a, n);
}
template <typename T>
inline void print_array9(T* a, int n) {
  print_space(n), print_array1(a, n);
}
template <typename T>
inline void print_array10(T* a, int n) {
  print_space(n), print_array3(a, n);
}
template <typename T>
inline void print_array11(T* a, int n) {
  print_space(n), print_array5(a, n);
}
template <typename T>
inline void print_array12(T* a, int n) {
  print_space(n), print_array7(a, n);
}
template <typename T>
inline void vector_print(vector<T> a, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) print_char(a[i], " \n"[i == r]);
}
template <typename T>
inline void map_print(map<T, T> a, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) print_char(a[i], " \n"[i == r]);
}
template <typename T>
inline void stack_print(stack<T> a, char ch) {
  while (!a.empty()) print_char(a.top(), ch), a.pop();
}
template <typename T>
inline void queue_print(queue<T> a, char ch) {
  while (!a.empty()) print_char(a.front(), ch), a.pop();
}
template <typename T>
inline void pq_print(priority_queue<T> a, char ch) {
  while (!a.empty()) print_char(a.top(), ch), a.pop();
}
inline void print_string_in_range(string s, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) putchar(s[i]);
}
inline void print_chars_in_range(char* a, int l, int r) {
  for (int(i) = (l); (i) <= (r); ++(i)) putchar(a[i]);
}
inline void print_allstring(string s) {
  print_string_in_range(s, 0, (int)s.size() - 1);
}
inline void filein(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void fileout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
inline void file(string s) { filein(s), fileout(s); }
}  // namespace fastExpress
using namespace fastExpress;
string out, in, s = "RRRRPSSPRR";
int main() {
  for (int(i) = (0); (i) <= (9); ++(i)) {
    cout << s[i] << endl;
    getline(cin, in);
    out += (in == "ai" ? "0" : "1");
  }
  if (out == "1111000011")
    s = "RRRRRRRRRR";
  else if (out == "0000100100")
    s = "PPPPPPPPPP";
  else if (out == "0000011000")
    s = "SSSSSSSSSS";
  else if (out == "0010000010")
    s = "SRPSRPSRPS";
  else if (out == "0000110000")
    s = "PSRPSRPSRP";
  else if (out == "0000000110")
    s = "SPRSPRSPRS";
  for (int(i) = (0); (i) <= (9); ++(i)) {
    cout << s[i] << endl;
    getline(cin, in);
  }
  return 0;
}
