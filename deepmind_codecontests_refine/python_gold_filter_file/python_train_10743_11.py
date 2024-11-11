class cep:
    def __init__(self,num,i):
        self.self=num
        self.i=i
def s(a):return a.self
q=int(input())
for _ in range(q):
    w,e=map(int,input().split())
    r=list(map(int,input().split()))
    if e<max(3,w):print(-1)
    else:
        ans=sum(r)*2
        e-=w
        for i in range(w):r[i]=cep(r[i],i+1)
        r.sort(key=s)
        ans+=e*(r[0].self+r[1].self)
        print(ans)
        for i in range(w):print(i+1,(i+1)%w+1)
        for i in range(e):print(r[0].i,r[1].i)