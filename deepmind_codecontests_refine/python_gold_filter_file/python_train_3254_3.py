t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    curm = p[0]
    cur = 1
    myparts = []
    for ele in p[1:]:
        if ele < curm:
            cur += 1
        else:
            curm = ele
            myparts.append(cur)
            cur = 1
    myparts.append(cur)
    poss = [0 for i in range(n+1)]
    poss[0] = 1
    #print(myparts)
    for ele in myparts:
        nextposs = list(poss)
        for i in range(n+1-ele):
            if poss[i]: nextposs[i+ele] = 1
        poss = nextposs
    #print(poss)
    if poss[n]: print("YES")
    else: print("NO")