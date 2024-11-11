n=int(input())
s=input()

l=list(s)
if n==2:
    print(s)
    exit()
if n%2==0:
    for i in range(0,n-2,2):
        print(l[i],end='')
        print(l[i+1],end='')
        print('-',end='')
    print(l[n-2],end='')
    print(l[n-1],end='')
    print()
else:
    if n==3:
        print(s)
    else:
        for i in range(0,n-3,2):
            print(l[i],end='')
            print(l[i+1],end='')
            print('-',end='')
        print(l[n-3],end='')
        print(l[n-2],end='')
        print(l[n-1],end='')
        print()