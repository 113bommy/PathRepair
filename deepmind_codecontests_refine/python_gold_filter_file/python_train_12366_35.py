h, w, k = map(int, input().split())
s = [list(map(int, list(input()))) for _ in range(h)]
result = []
if h*w<=k:
    result.append(0)
else:
    for i in range(2**(h-1)):
        checker, num, p = 0, i ,[0]
        for _ in range(h):
            p.append(p[-1]+num%2)
            checker += num%2
            num >>= 1
        x = 0
        c = [0 for _ in range(checker+1)]
        for j in range(w):
            num = i
            nex = [0 for _ in range(checker+1)]
            for m in range(h):
                nex[p[m]] += s[m][j]
            if max(nex) > k:
                x = float('inf')
                break            
            for m in range(checker+1):
                c[m] += nex[m]
                if c[m]>k:
                    c = nex
                    x += 1
                    break
        result.append(checker+x)
print(min(result))