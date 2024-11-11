R = lambda: map(int, input().split())
n, m = R()

b0 = []
for i in range(110): b0.append([0]*110)

b1 = []
for i in range(1, n+1):
    s = input()
    b1.append(s.replace('.', '0'))
    for j in range(1, m+1):
        if s[j-1] == '*':
            b0[i-1][j-1] += 1
            b0[i-1][j] += 1
            b0[i-1][j+1] += 1
            b0[i][j-1] += 1
            b0[i][j+1] += 1
            b0[i+1][j-1] += 1
            b0[i+1][j] += 1
            b0[i+1][j+1] += 1

ans = 'YES'
for i in range(n):
    for j in range(m):
        if '0' <= b1[i][j] <= '8':
            if int(b1[i][j]) != b0[i+1][j+1]:
                ans = 'NO'

print(ans)
