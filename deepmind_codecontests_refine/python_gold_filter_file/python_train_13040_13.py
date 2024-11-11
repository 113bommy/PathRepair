s=0
for tc in range(int(input())):
    n=int(input())
    x=list(map(int,input().split()))
    y=list(map(int,input().split()))
    for i in range(n):
        s+=max(x[i]-min(x),y[i]-min(y))
    print(s)    
    s=0