n = int(input())
lis = list(map(int, input().split()))

def dfs(arr, pos):
    if pos<0 or len(arr)==0:
        return 0

    l1 = []
    l2 = []
    for i in arr:
        if i>>pos & 1==0:
            l1.append(i)
        else:
            l2.append(i)


    if not l1:
        return dfs(l2, pos-1)

    elif not l2:
        return dfs(l1, pos-1)

    else:
        # print(1<<pos)
        return min(dfs(l1, pos-1), dfs(l2, pos-1)) + (1<<pos)



print(dfs(lis, 30))