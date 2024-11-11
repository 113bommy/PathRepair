N = int(input())
csf = [tuple(map(int,input().split())) for i in range(N-1)]

for i in range(N-1):
    t = 0
    for c,s,f in csf[i:]:
        t = max(t, s)
        if t%f:
            t += -t%f
        t += c
    print(t)

print(0)