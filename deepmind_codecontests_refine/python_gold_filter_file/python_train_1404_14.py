


n,k = map(int,input().split())

t = list(map(int,input().split()))

T =sorted(t)
u=0
h=0
m=[]

for j in range(n):
    if u+T[j]<=k:
        u+=T[j]
        c = t.index(T[j])
        m.append(c+1)
        t[c]=-1
        h+=1
    else:
        break

    
m.sort()
print(h)
print(*m)
