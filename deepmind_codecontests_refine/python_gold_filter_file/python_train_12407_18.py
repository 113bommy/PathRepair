import sys
input = sys.stdin.readline

n = int(input())
s = list(input())
a = []
b = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

cnt = s.count('1')
ans = cnt
for t in range(1, 1000):
    for i in range(n):
        if t >= b[i] and (t - b[i]) % a[i] == 0:
            if s[i] == '1':
                s[i] = '0'
                cnt -= 1
            else:
                s[i] = '1'
                cnt += 1
    ans = max(ans, cnt)
print(ans)
