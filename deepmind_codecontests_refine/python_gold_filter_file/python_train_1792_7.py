S = input().strip()
P = []
j = 0
for i in range(1, len(S)+1):
    if i == len(S) or S[i] != S[j]:
        P.append((S[j], i-j))
        j = i
l = 0
r = len(P)-1
while l < r:
    if P[l][0] != P[r][0] or P[l][1] + P[r][1] < 3:
        break
    l += 1
    r -= 1

if l == r and P[l][1] >= 2:
    print(P[l][1]+1)
else:
    print(0)
