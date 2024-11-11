T=int(input())
for i in range(T):
    n,m=map(int,input().split())
    if n==1:
        print(0)
    elif n==2:
        print(m)
    elif n>2:
        print(2*m)