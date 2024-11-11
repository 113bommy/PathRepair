h,w=map(int,input().split())
print('#'*(w+2))
for _ in [0]*h:
  print('#'+input()+'#')
print('#'*(w+2))