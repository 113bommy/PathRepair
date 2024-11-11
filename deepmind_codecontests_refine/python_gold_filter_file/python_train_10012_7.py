p = int(input())
for i in range(p):
    q = int(input())
    a = sorted(list(map(int,input().split())))
    mx = 0
    for k in range(q-1):
        if a[-1]>=k+1 and a[-2]>=k+1:
            mx = k
    print(mx)



