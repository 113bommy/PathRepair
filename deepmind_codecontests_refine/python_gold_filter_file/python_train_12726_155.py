t=int(input())
for g in range(t):
    n,m=map(int,input().split())
    if(n>=3):
        print(2*m)
    elif(n==2):
        print(m)
    else:
        print(0)