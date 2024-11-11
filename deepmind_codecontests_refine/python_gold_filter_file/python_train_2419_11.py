t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    m=a%b
    if(m):
        print(b-m)
    else:
        print(0)
    
