for _ in range(int(input())):
    n,m,a,b=map(int,input().split())
    if n*a!=m*b:
        print("NO")
        continue
    print("YES")
    d = 1
    while (d*n)%m!=0 and d<m:d+=1
    s='1'*a+'0'*(m-a)
    for _ in range(n):
        print(s)
        s=s[-d:]+s[:-d]