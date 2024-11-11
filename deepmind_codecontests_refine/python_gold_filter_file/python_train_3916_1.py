debug = 0
read = lambda: map(int, input().split())
k, n = read()
a = list(read())
cnt4 = k
cnt2 = 2 * k
for i in range(n):
    cnt = min(cnt4, a[i] // 4)
    a[i] -= cnt * 4
    cnt4 -= cnt
if debug: print(*a)
for i in range(n):
    cnt = min(cnt2, a[i] // 2)
    a[i] -= cnt * 2
    cnt2 -= cnt
if debug: print(' '.join(map(str, a)), ' ', cnt2, cnt4)
c = [0] * 20
for i in a:
    c[min(i, 19)] += 1
if debug:
    print(cnt2, cnt4, c)
d = min(cnt4, c[3])
c[3] -= d
cnt4 -= d
d = min(cnt4, c[1], c[2])
c[1] -= d
c[2] -= d
cnt4 -= d
d = min(cnt2, c[2])
c[2] -= d
cnt2 -= d
d = min(cnt2, c[1])
c[1] -= d
cnt2 -= d
d = min(cnt4, (c[2] + 2) // 3 + int(c[2] > 1))
c[2] -= d + d // 2
cnt4 -= d
if debug:
    print('cnt4 = ', cnt4)
    print('c[1] = ', c[1])
d = min(cnt4, c[2])
c[2] -= d
cnt4 -= d
d = min(cnt4, (c[1] + 1) // 2)
c[1] -= d * 2
cnt4 -= d
d = min(cnt4, c[1])
c[1] -= d
cnt4 -= d
print('YES' if sum(c[1:]) == 0 else 'NO')