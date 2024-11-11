n = int(input())
s = list(map(int, input().split()))
q  = int(input())
t = [0]*n
t[0] = s[0]
for i in range(1, n):
    t[i] += t[i - 1] + s[i]
for i in range(q):
    l, r = map(int, input().split())
    print((t[r - 1] - t[l - 1] + s[l - 1])//10)
