h,w = map(int,input().split())
w += 2
print('#'*w)
for i in range(h):
    print('#' + input() +'#')
print('#'*w)