n,x = map(int, input().split())
if 1 < x < (2*n - 1):
    print("Yes")
    if n == 2:
        for i in range(3):
            print(i+1)
        exit()
    if x != 2:
        ans = [-1 for i in range(2*n-1)]
        k = (n*2-1) //2
        ans[k-1] = x-1
        ans[k] = x
        ans[k+1] = x+1
        ans[k+2] = x-2
        used = set([x-1,x,x+1,x-2])
        insert = iter([i+1 for i in range(n*2-1) if (i+1) not in used])
        for i in range(2*n-1):
            if ans[i] == -1:
                ans[i] = insert.__next__()
        for i in range(n*2-1):
            print(ans[i])
    else:
        ans = [-1 for i in range(2*n-1)]
        k = (n*2-1) // 2
        ans[k-1] = x+2
        ans[k] = x
        ans[k+1] = x-1
        ans[k+2] = x+1
        used = set([x+1,x,x+2,x-1])
        insert = iter([i+1 for i in range(n*2-1) if (i+1) not in used])
        for i in range(2*n-1):
            if ans[i] == -1:
                ans[i] = insert.__next__()
        for i in range(n*2-1):
            print(ans[i])
else:
    print("No")