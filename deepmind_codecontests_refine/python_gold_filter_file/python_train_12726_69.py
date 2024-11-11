t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    if n>=3:
        print(2*m)
    elif n==1:
        print(0)
    else:
        print(m)