n = int(input())
S=[]
for _ in range(n):
    x,w = list(map(int,input().split()))
    S.append((x,w))
S = sorted(S,key=lambda kv:kv[0]+kv[1])
m=1
last=S[0]
for kv in S[1:]:
    if abs(kv[0]-last[0]) >= kv[1]+last[1]:
        m+=1
        last=kv
print(m)

