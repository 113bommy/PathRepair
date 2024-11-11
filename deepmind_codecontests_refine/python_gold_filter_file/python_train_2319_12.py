def ind(lst,m):
    result=[]
    for ab in range(m):
        result.append([-1])
    #print(result)
    for z in range(m):
        #print(lst[z]-1)
        result[lst[z]-1].append(z)
    for ab in range(m):
        result[ab].append(m)
    #print(result)
    return result

t = int(input())
for i in range(t):
    n = int(input())
    ans = [-1]*n
    a = [int(x) for x in input().split()]
    s = set(a)
    te = ind(a,n)
    for j in s:
        maxx = -1
        for k in range(len(te[j-1])-1):
            maxx = max(maxx,te[j-1][k+1]-te[j-1][k])
        for k in range(maxx-1,n):
            if ans[k]!=-1:
                if ans[k]>j:
                    ans[k]=j
                else:
                    break
            else:
                ans[k]=j
    print(*ans)
