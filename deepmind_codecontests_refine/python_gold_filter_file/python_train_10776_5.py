R = lambda : map(int, input().split())
n,m = R()

graph = [set() for _ in range(n)]

for i in range(m):
    u,v = R()
    graph[u-1].add(v-1)
    graph[v-1].add(u-1)

l = [-1]*n

for i in range(n):
    if len(graph[i])==n-1:
        l[i]=1

for i in range(n):
    if l[i]==-1:
        l[i] = 0
        for j in range(n):
            if j in graph[i] and l[j] != 1:
                l[j] = 0
        break   

for i in range(n):
    if l[i]==-1:
        l[i] = 2 

for i in range(n):
    for j in range(i+1,n):
        if l[i]==-1 or l[j]==-1:
            print("No"); exit()
        elif l[i]==1 or l[j]==1:
            if j not in graph[i]:
                print("No"); exit()
        elif l[i]==l[j]:
            if j not in graph[i]:
                print("No"); exit()
        elif l[i]!=l[j]:
            if j in graph[i]:
                print("No"); exit()

res = ""
for i in range(n):
    if l[i]==0:
        res += "a"
    elif l[i]==1:
        res += "b"
    else:
        res += "c"

print("Yes")
print(res)
