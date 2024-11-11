t=int(input())
while(t):
    n=int(input())
    a=[]
    for i in range(2,n+2):
        a.append(i)
    print(*a)
    t-=1