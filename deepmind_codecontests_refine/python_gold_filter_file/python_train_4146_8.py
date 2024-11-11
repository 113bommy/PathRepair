from collections import Counter
N = int(input())
A = [int(i) for i in input().split()]

c = Counter(A)
b = sorted(c.keys())

ret = 0
for j in range(len(c) - 1, -1, -1) :
    i = 2
    while c[b[j]] > 0 and i - b[j] <= b[j] :
        if b[j] != i - b[j] :
            if c[b[j]] > 0 and c[i-b[j]] > 0 :
                M = min(c[b[j]], c[i-b[j]])
                ret += M
                c[b[j]] -= M
                c[i-b[j]] -= M
        else :
            if c[b[j]] > 1 :
                ret += c[b[j]] // 2
                c[b[j]] %= 2
        i *= 2
    
print(ret)
