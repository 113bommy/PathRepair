n=int(input())
for z in range(n):
    l,r=map(int,input().split())
    t=r//2
    if r%2: 
        t-=r
    l-=1
    m=l//2
    if l%2: m-=l
    print(t-m)
    
