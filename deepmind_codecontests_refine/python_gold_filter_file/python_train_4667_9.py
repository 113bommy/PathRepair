h,w=map(int,input().split())
a=[]
for _ in [0]*h:
    ai=list(input())
    #print(ai)
    if "#" in ai:
        a.append(ai)
t=[]
for wi in zip(*a):
    if "#" in wi:
        t.append(wi)
for ans in zip(*t):
    print("".join(ans))
