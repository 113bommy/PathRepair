r,c = map(int, input().split())

for j in range(r):
    if j%2==0:
        print('#'*c)
    else:
        if j in range(1,r,4):
            print('.'*(c-1)+'#')
        else:
            print('#' + '.'*(c-1))