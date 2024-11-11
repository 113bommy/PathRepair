t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    if(n==1):
        result=0
    elif(n==2):
        result=m
    else:
        result=m*2
    print(result)    
        