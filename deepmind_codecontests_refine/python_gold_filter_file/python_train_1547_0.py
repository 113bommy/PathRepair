import sys
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

q = []
checked = [-1]*N
for n in range(N):
    if len(graph[n]) == 1:
        q.append(n)
        checked[n] = 0

ok = False
while q:
    posiq = []
    for p in q:
        update = False
        for np in graph[p]:
            if checked[np] == -1:
                checked[np] = checked[p] + 1
                update = True
                posiq.append(np)
            elif checked[np] == checked[p] + 1:
                ok = True
                break
            elif checked[np] == checked[p]:
                update = True
        if not update:
            ok = True
            break
    
    q = set()
    for p in posiq:
        for np in graph[p]:
            if checked[np] == -1 and not np in q:
                c = 0
                for mp in graph[np]:
                    if checked[mp] == -1:
                        c += 1
                    if c >= 2: break
                if c <= 1:
                    q.add(np)
    for np in q:
        checked[np] = checked[p] + 1

print("First" if ok else "Second")            
