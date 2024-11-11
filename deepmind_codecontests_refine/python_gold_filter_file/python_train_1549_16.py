n,k = [int(i) for i in input().split()]
edges = [[int(i)-1 for i in input().split()] for j in range(n-1)]

node = [[] for _ in range(n)]
for edge in edges:
    node[edge[0]].append(edge[1])
    node[edge[1]].append(edge[0])

M = 0
for i in range(n):
    count = 1
    que = []
    check = [False]*n
    if k%2==0:
        check[i] = True
        que.append(i)
    elif i!=n-1:
        check[edges[i][0]]=True
        check[edges[i][1]]=True
        que.append(edges[i][0])
        que.append(edges[i][1])
        count = 2
    for j in range(k//2):
        newque = []
        while len(que)!=0:
            q = que.pop()
            for l in node[q]:
                if check[l]:
                    continue
                newque.append(l)
                check[l] = True
                count += 1
        que = newque
    M = max(M,count)
print(n-M)