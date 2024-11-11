n,m=map(int,input().split())
arr=dict()
for i in range(n):
    a,b=map(str,input().split())
    arr[b]=a
for i in range(m):
    a,b=map(str,input().split())
    c=b[:-1]
    print(a,b,end=' ')
    print('#',end='')
    print(arr[c])

