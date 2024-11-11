h, w, k = map(int, input().split())
S = [[int(s) for s in list(input())] for i in range(h)]
ans = 10**4
for b in range(2**(h-1)):
    cnt = bin(b).count('1')
    B = format(b, 'b').zfill(h-1)+'1'
    T = [[0]*w for i in range(cnt+1)]
    for j in range(w):
        t, c = 0, 0
        for i in range(h):
            t += S[i][j]
            if B[i] == '1':
                T[c][j] += t
                t = 0
                c += 1
    if max([max(T[i]) for i in range(cnt+1)]) > k:
        continue
    A = [T[i][0] for i in range(cnt+1)]
    tmp = cnt
    for j in range(1, w):
        A = [A[i]+T[i][j] for i in range(cnt+1)]
        if any([a > k for a in A]):
            A = [T[i][j] for i in range(cnt+1)]
            tmp += 1
    ans = min(ans, tmp)
print(ans)
