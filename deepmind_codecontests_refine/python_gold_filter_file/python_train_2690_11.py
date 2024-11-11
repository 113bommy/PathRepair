H,W=map(int,input().split())
S=[list(map(int, input().split())) for i in range(10)]
l=[None]*10
for i in range(10):
    l[i]=S[i][1]
for i in range(6):
    for j in range(10):
        for k in range(10):
            if l[j]>l[k]+S[j][k]:
                l[j]=l[k]+S[j][k]
l.append(0)
a=0
for i in range(H):
    L=list(map(int,input().split()))
    for j in L:
        a+=l[j]
print(a)