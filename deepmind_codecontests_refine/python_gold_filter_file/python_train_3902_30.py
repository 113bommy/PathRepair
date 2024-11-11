n,m=map(int,input().split())
count=0
for i in range(1,n+1):
    if(i%2==0):
        count+=1 
        if (count%2==0):
            print('#',end='')
            for j in range(2,m+1):
                print('.',end='')
        else:
            for j in range(1,m):
                print('.',end='')
            print('#',end='')
    else:

       for j in range(1,m+1):
           print('#',end='') 
    print('',end='\n')

    