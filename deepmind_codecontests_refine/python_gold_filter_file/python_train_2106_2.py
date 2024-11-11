q = int(input())

def inter(a,b):
    return (max(a[0],b[0]), min(a[1],b[1]))

for i in range(q):
    n,m=map(int,input().split())
    rang = (m,m)
    last=0
    
    good = True
    for i in range(n):
        t,l,h = map(int,input().split())
        
        if not good:
            continue
        
        minutes=t-last
        last=t
        rang = (rang[0]-minutes, rang[1]+minutes)
        
        comp=inter((l,h),rang)
        if comp[0] > comp[1]:
            good = False
        rang = comp
    
    if good:
        print("YES")
    else:
        print("NO")