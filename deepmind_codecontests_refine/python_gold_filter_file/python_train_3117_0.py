while True:
    P = list()
    ans = list()
    tans = list()
    m, Mn, Mx = map(int, input().split())
    if m == 0 and Mn == 0 and Mx == 0:
        break
    for i in range(0, m):
        P.append(int(input()))

    for j in range(Mn-1, Mx, 1):
        ans.append(P[j]-P[j+1])
    #print(ans)
    for k in range(0,len(ans)):
        if ans[k] == max(ans):
            tans.append(k)
    #print(tans)
    print(max(tans)+Mn)

