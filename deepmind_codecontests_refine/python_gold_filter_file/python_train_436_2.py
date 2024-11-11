t=int(input())
for i in range(t):
    n = int(input())
    mx = 0
    mn = 991000000000
    sred = 0
    m = list(map(int,input().split()))
    for i in range(n):
        if m[i] == -1:
            continue
        if i != 0:
            if m[i-1] == -1:
                if mx < m[i]:
                    mx = m[i]
                if mn > m[i]:
                    mn = m[i]
            else:
                if abs(m[i-1] - m[i]) > sred:
                    sred = abs(m[i-1] - m[i])
            if i != n-1:
                if m[i+1] == -1:
                    if mx < m[i]:
                        mx = m[i]
                    if mn > m[i]:
                        mn = m[i]
                else:
                    if abs(m[i+1] - m[i]) > sred:
                        sred = abs(m[i+1] - m[i])
        else:
            if m[i+1] == -1:
                if mx < m[i]:
                    mx = m[i]
                if mn > m[i]:
                    mn = m[i]
            else:
                if abs(m[i+1] - m[i]) > sred:
                    sred = abs(m[i+1] - m[i])
    r = mx+mn
    if mn > 1000000000:
        print(0,0)
        continue
    if sred > max(mx-r//2, r//2 - mn):
        print(sred, r//2)
    else:
        print(max(mx-r//2, r//2 - mn), r//2)
