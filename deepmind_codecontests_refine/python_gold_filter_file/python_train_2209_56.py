n=int(input())
for i in range(n):
    a=int(input())
    b=a
    while a!=0:
        i=a
        a=a//10
        if a==0:
           break
        b=b+a
        a=a+i%10
    print(b)