n,m = map(int,input().split())
for i in range(n//2):
    print('#'*m)
    if i % 2 == 0:
        print('.'*(m-1)+'#')
    else:
        print('#'+'.'*(m-1))
print('#'*m)
