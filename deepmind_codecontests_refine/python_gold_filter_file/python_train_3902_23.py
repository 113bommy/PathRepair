n,m=map(int,input().split())
l=1
for i in range(1,n+1):
    if(i&1):
        print('#'*m)
    else:
        if(l==1):
            print('.'*(m-1)+'#')
            l=0
        else:
            print('#'+'.'*(m-1))
            l=1

        