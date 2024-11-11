#include <bits/stdc++.h>
int length = 0;
char* strXml;
void init() { length = 0; }
template <typename T>
class vectorClass {
  int* arr;
  int capacity;
  int current;

 public:
  vectorClass() {
    arr = new T[1];
    capacity = 1;
    current = 0;
  }
  void push(T data) {
    if (current == capacity) {
      T* temp = new T[2 * capacity];
      for (int i = 0; i < current; i++) {
        temp[i] = arr[i];
      }
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }
  }
  void push(int data, int index) {
    if (index == capacity) {
      push(data);
    } else {
      arr[index] = data;
    }
  }
  T get(int index) {
    if (index < capacity) return arr[index];
  }
  void pop() { current--; }
  int getCapacity() { return capacity; }
  void print() {
    for (int i = 0; i < capacity; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
};
void takeInput() { scanf("%s", strXml); }
void processResult() {
  while (*strXml) {
    if (*strXml == '<' && *(strXml + 1) >= 97 && *(strXml + 1) <= 123) {
      for (int i = 0; i < length; i++) printf(" ");
      printf("<");
      printf("%c", *(strXml + 1));
      printf(">\n");
      strXml += 2;
      length++;
    }
    if (*strXml == '<' && *(strXml + 1) == '/' && *(strXml + 2) >= 97 &&
        *(strXml + 2) <= 123) {
      length--;
      for (int i = 0; i < length; i++) printf(" ");
      printf("<");
      printf("\/");
      printf("%c", *(strXml + 2));
      printf(">\n");
      strXml += 3;
    }
    strXml++;
  }
}
int main() {
  init();
  strXml = (char*)malloc(sizeof(char) * 2000);
  takeInput();
  processResult();
  return 0;
}
