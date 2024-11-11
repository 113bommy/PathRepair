n=int(input())
if n%4==0:
    print('0')
    print(n//2)
    for i in range(1,n+1):
        if i%4==1 or  i%4==0:
            print(i)
elif n%4==1:
    print('1')
    print(n//2+1)
    for i in range(1,n+1):
        if  i%4==1 or i%4==2:
            print(i)
elif n%4==2:
    print('1')
    print(n//2)
    for i in range(1,n+1):
        if  i%4==1 or i%4==0:
            print(i)
else:
    print('0')
    print(n//2+1)
    for i in range(1,n+1):
        if i%4==1 or i%4==2:
            print(i)