for test in range(int(input())):
    n=int(input())
    if n<=9:
        print(n)
        continue
    c=9
    x=11
    while x<=n:
        for j in range(1,10):
            if j*x<=n:
                c+=1
        x= x*10 + 1
    print(c)