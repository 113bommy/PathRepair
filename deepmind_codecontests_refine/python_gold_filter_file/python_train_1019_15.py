#coding: utf-8
N = int(input())
S = list(input())
ans = S.count(".")
cnt = ans
for i in range(N):
    if S[i] == "#":
        cnt += 1
    else:
        cnt -= 1
    ans = min(ans, cnt)
print(ans)