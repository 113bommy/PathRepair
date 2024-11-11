from collections import Counter
N,K = map(int,input().split())
S = input()

C = Counter(S)

cnt = 0
for i in range(26):
    c = chr(97+i)
    if cnt + C[c] >= K:
        break
    else:
        cnt += C[c]
        S = S.replace(c,"")

t = ""
for s in S:
    if s == c and cnt < K:
        cnt += 1
    else:
        t += s
else:
    S = t

print(S)
