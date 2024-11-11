n = int(input())
s = input()
t = input()
s0 = sorted(list(s))
t0 = sorted(list(t))
if s0 != t0 :
    print(-1)
else:
    ans = []
    for i in range(n):
        j = 0
        while (s[j] != t[i]):
            j = j + 1
        ans += [n - j - 1, 1, n]
        s = ''.join(reversed(s[:j])) + s[j + 1:] + s[j]
    print(len(ans))
    print(" ".join(str(i) for i in ans))