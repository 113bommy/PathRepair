n=int(input())
if n==3:
    print(6)
elif n==4:
    print(18)
else:
    a=18
    for i in range(5,n+1):
        a+=i*(i-1)
    print(a)