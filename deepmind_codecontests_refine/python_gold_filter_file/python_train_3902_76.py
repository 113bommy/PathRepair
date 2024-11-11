k = 1
temp = 0
n,m = map(int,input().split())

for i in range(n):
    for j in range(m):
        if (i+1)%2==0:
         temp = 1
         if k%2!=0:
          if j!=m-1:
            print('.',end = '')
          else:
            print('#',end='')
         else:
             if j==0:
                print('#',end = '')
             else:
                print('.',end='')



        else:
            temp = 0
            print('#',end='')


    print('')
    if temp == 1:
        k+=1




