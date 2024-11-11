from math import inf
t = int(input())
for i in range(t):
    l = int(input())
    nums = list(map(int, input().split()))
    if l < 2:
        print(-1)
        continue
    else:
        dis = inf
        lst = [None] * (l+10)
        for j in range(l):
            # print(j)
            # print(lst[nums[j]])
            if lst[nums[j]] is None:
                lst[nums[j]] = j
            elif dis >= j - lst[nums[j]]:
                dis = j - lst[nums[j]]
            lst[nums[j]] = j
        if dis == inf:
            print(-1)
        else:
            print(dis+1)


