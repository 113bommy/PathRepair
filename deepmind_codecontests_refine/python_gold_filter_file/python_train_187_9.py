#080-C 
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return list(input())
n=I()
F=[int(input().replace(" ",""), 2) for _ in range(n)]
P=[IL() for i in range(n)]
ans=-pow(10,10)
for i in range(1,pow(2,10)):
    t=0
    for f,p in zip(F,P):
        t+=p[bin(f&i).count("1")]
    ans=max(ans,t)
print(ans)