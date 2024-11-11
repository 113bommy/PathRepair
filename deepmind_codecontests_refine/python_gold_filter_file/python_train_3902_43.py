n,m=map(int,input().split())
c=0
for i in range(0,n):
    d=i+1
    if d%2==1:
        for j in range(0,m):
            print("#",end="")
        c=c+1
    else:
        if c==1:
            for j in range(0,m-1):
                print('.',end='')
            print('#',end='')
        if c==2:
            print('#',end='')
            for j in range(1,m):
                print('.',end='')
            c=0
    print()        
        
        
    
        