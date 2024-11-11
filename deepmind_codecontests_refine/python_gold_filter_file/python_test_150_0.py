t = int(input())
for c in range(t):
    n = int(input())
    a = sorted(list(set(map(int, input().split()))))
    m = a[-1]
    # print(t,n,a)
    k = max([x // 3 for x in a])
    mod3s = sorted(list(set([x%3 for x in a])))

    # print(mod3s)                # 
    if mod3s == [0]:
        ans = k
    elif mod3s == [1]:
        ans = k+1
    elif mod3s == [2]:
        ans = k+1
    elif mod3s == [0,1]:
        ans = k+1
    elif mod3s == [0,2]:
        ans = k+1
    elif mod3s == [1,2] or mod3s == [0,1,2]:
        if m%3 == 0:
            ans = k+1
        elif m%3 == 1:
            if a[-2] == m-1 or a[0] == 1:
                ans = k+2
            else:
                ans = k+1
        else:
            ans = k+2
    print(ans)
