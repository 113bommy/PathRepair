N,M = map(int,input().split())

A = [[] for i in range(N)]

for i in range(M) :
    l,r,d = map(int,input().split())
    
    l -= 1
    r -= 1
    
    A[l].append([r,d])
    A[r].append([l,-d])
    
ans = "Yes"

distance = ["#" for i in range(N)]

flg = 0

for i in range(N) :
    if flg :
        break
    
    if distance[i] != "#" :
        continue
    
    distance[i] = 0
    stack = [i]
    
    while stack :
        now = stack.pop()
        
        for to,d in A[now] :
            if distance[to] == "#" :
                distance[to] = distance[now] + d
                stack.append(to)
            
            elif distance[to] != distance[now] + d :
                ans = "No"
                stack = []
                flg = 1
                break
            
print(ans)
