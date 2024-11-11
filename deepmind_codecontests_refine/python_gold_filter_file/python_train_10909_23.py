N = int(input())
S = list(input())

ans = 0
for i in range(10**3):
    mm = 0
    num = str(i).zfill(3)
    for j in range(N):
        if num[mm]==S[j]:
            mm += 1
        if mm==3:
            ans += 1
            break
print(ans)