n = int(input())
s = input()
t = input()
ans = list()
if sorted(s) == sorted(t):
    for i in range(n):
        ind = s[i:].index(t[i]) + i
        for j in range(ind - 1, i - 1, -1):
            ans.append(j + 1)
        s = s[:i] + t[i] + s[i:ind] + s[ind + 1:]
    print(len(ans))
    print(*ans)
else:
    print(-1)