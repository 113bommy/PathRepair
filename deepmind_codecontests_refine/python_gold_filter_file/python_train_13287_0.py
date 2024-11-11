n,a,b=map(int,input().split())
mp=min(int((a+b)/n),a,b)
while True:
    if a//mp+b//mp<n:
        mp-=1
    else:
        print(mp)
        break
    
