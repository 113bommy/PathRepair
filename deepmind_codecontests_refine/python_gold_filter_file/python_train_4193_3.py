for i in range(int(input())):
    n,m=[int(num) for num in input().split()]
    lst=list()
    c=0
    c1=0
    for i in range(n):
        x=input()
        if i==(n-1):
            y=x
        lst.append(x[-1])
    if len(y)!=0:
        for i in range(len(y)-1):
            if y[i]=='D':
                c=c+1
    for i in range(len(lst)):
        if lst[i]=='R':
            c1=c1+1
    print(c+c1)
