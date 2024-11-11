N = int(input())
S = input()
ans = 0
for i in range(10**3):
    s = str(i).zfill(3)
    flag = 0
    for j in range(N):
        if s[flag]==S[j]:
            flag += 1
            if flag == 3:
                break
    if flag==3:
        ans += 1
print(ans)