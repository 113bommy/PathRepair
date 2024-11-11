from sys import stdin
input = stdin.readline

def find(i):
    if i==p[i]:
        return i
    p[i]=find(p[i])
    return p[i]

def union(i,j):
    if rank[i]>rank[j]:
        i,j = j,i
    elif rank[i]==rank[j]:
        rank[j]+=1
    p[i]=j


z = []
t = int(input())
for _ in range(t):
    n = int(input())
    a,b = input(), input()
    edge = []
    ans = 0
    A = ord('a')
    for i in range(n):
        if ord(a[i])<ord(b[i]):
            edge.append((1, ord(a[i])-A, ord(b[i])-A))
        elif ord(a[i])==ord(b[i]):
            pass
        else:
            ans = -1
            break
    if ans==0:
        p = list(range(20))
        rank = [0]*20
        for w,x,y in edge:
            x,y = find(x),find(y)
            if x!=y:
                union(x,y)
                ans+=w
    z.append(ans)
print(*z)

