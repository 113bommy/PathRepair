import math
t = int(input())
for _ in range(t):
    n = int(input())
    li = []
    for i in range(n):
        ali = input()
        ali = list(ali)
        li.append(ali)
    # print(li)
    q = int(li[0][1])
    w = int(li[1][0])
    e = int(li[n-2][n-1])
    r = int(li[n-1][n-2])
    cnt = 0
    ans = []
    if(q == 0 and w == 0):
        if(e != 1):
            cnt += 1
            ans.append((n-1,n))
        if(r != 1):
            cnt += 1
            ans.append((n,n-1))
    elif(q == 1 and w == 1):
        if(e != 0):
            cnt += 1
            ans.append((n-1,n))
        if(r != 0):
            cnt += 1
            ans.append((n,n-1))
    else:
        if(e == r):
            if(q == r):
                cnt += 1
                ans.append((1,2))
            if(w == r):
                cnt += 1
                ans.append((2,1))
        else:
            if(q != 0):
                cnt += 1
                ans.append((1,2))
            else:
                cnt += 1
                ans.append((2,1))
            if(e != 1):
                cnt += 1
                ans.append((n-1,n))
            else:
                cnt += 1
                ans.append((n,n-1))
    print(cnt)
    for i in range(len(ans)):
        print(*ans[i])






        
    



