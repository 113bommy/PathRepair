s = input()
m = int(input())
for i in range(m):
    l, r, k = map(int, input().split())
    ss = s[l - 1: r]
    n = len(ss)
    k %= n
    s = s[:l - 1] + ss[n - k:] + ss[:n - k] + s[r:]
print(s)
