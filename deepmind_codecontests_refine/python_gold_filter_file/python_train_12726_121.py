t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    if(n==1):
        print(0)
    elif(n==2):
        print(k)
    else:
        print(2*k)