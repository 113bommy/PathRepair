t=int(input())
for i in range(t):
    nm=list(map(int,input().strip().split()))
    n=nm[0]
    m=nm[1]
    if n==1:
        print(0)
    elif n==2:
        print(m)
    else:
        print(2*m)