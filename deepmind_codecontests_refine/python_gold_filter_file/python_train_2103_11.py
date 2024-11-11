for _ in range(int(input())):
    a,b,c,d,k=[int(x) for x in input().split()]
    if c>=a:
        num1=1
    else:
        num1=(a//c)
        if (a%c):
            num1+=1
    if d>=b:
        num2=1
    else:
        num2=(b//d)
        if b%d:
            num2+=1
    if num2+num1<=k:
        print(num1,num2)
    else:
        print(-1)
        