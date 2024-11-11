ch=input()
L=[int(i)for i in ch.split()]
a=L[0]
b=L[1]

if a>b:
    print(-1)
elif a==b:
    if a==0:
        print(a)
    else:
        print(1)
        print(a)

else:
    if (b-a)%2==1:
        print(-1)
    else:
        if a & (b-a)//2==0:
            print(2)
            print(a+(b-a)//2,(b-a)//2)
        else:
            print(3)
            print(a,(b-a)//2,(b-a)//2)
