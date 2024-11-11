n = int(input())
rt = {}
clist = [0 for i in range(n)]
for i in range(n):
    id, k, *c = list(map(int, input().split()))
    for j in c:
        rt[j] = id
    clist[id] = c
for i in range(n):
    print("node %d: parent = "%i, end = "")
    p = [i]
    while 1:
        try:
            p.append(rt[p[-1]])
        except:
            break
    if len(p) == 1:
        print("-1, depth = 0, root,",clist[i])
    else:
        print("%d, depth ="%p[1] ,len(p) - 1, end = "")
        if clist[i] == []:
            print(", leaf, []")
        else:
            print(", internal node,",clist[i])
