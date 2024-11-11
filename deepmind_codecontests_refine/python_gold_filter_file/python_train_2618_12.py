n,m = map(int,input().split())
if m%n!=0:
    print(-1)
else:
    c=0
    m = m//n
    while m%2==0:
        m = m//2
        c+=1
    while m%3==0:
        m = m//3
        c+=1
    if m!=1: c=-1
    print(c)
