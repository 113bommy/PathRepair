test=int(input())
while test>0:
    test=test-1
    a,b=input().split()
    a=int(a)
    b=int(b)
    p=a*b
    res=(p//2)+(p%2)
    print(res)