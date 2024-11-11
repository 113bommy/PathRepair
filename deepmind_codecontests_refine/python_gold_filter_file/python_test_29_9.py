t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    count_0 = 0
    count_1 = 0
    for i in range(n):
        if l[i] == 0:
            count_0 += 1
        elif l[i] == 1:
            count_1 += 1
    if count_1 == 0:
        ans = 0
    else:
        if count_0 == 0:
            ans = count_1
        else:
            ans = count_1*(2**count_0)
    print(ans)