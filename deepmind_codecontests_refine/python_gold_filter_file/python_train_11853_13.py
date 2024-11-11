h,w = map(int, input().split())
print('#'*(w+2))
for _ in range(h):
  print('#' + input() + '#')
print('#'*(w+2))