for _ in range(int(input())):
    n=int(input())
    l=[int(i) for i in input().split()]
    a=l[0]
    for i in range(1,n):
        a=a&l[i]
    if(l.count(a)==1):
        print(0)
        continue
    b=l.count(a)
    b=(b*(b-1))%(10**9+7)
    for i in range(1,n-1):
        b=(b*(i%(10**9+7)))%(10**9+7)
    print(b)