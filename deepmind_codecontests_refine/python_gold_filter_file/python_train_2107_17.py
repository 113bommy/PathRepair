q = int(input())
for i in range(q):
    n = int(input())
    ti = list(map(int,input().split()))
    ci = [0] * n
    ci[0] = 1
    num = -1
    for i in range(1,n-1):
        if ti[i] == ti[i-1]:
            ci[i] = ci[i-1]
            num = i
        else:
            ci[i] = 3 - ci[i-1]
    if n > 2 and ti[-1] != ti[0] and ti[-2] != ti[-1]:
        if ci[-2] != ci[0]:
            if num == -1:
                ci[-1] = 3
            else:
                for i in range(num,n):
                    ci[i] = 3 - ci[i-1]
        else:
            ci[-1] = 3 - ci[0]
    elif ti[-1] != ti[0]:
        ci[-1] = 3 - ci[0]
    elif ti[-2] != ti[-1]:
        ci[-1] = 3 - ci[-2]
    else:
        ci[-1] = ci[0]
    print(max(ci))
    print(" ".join(list(map(str,ci))))
