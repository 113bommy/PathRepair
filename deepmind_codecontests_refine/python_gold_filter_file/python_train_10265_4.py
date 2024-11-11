from itertools import dropwhile


n, m = map(int, input().split())
m += 2

p = list(dropwhile(lambda line: '1' not in line, (input() for i in range(n))))
p.reverse()
addition = len(p) - 1
p = list(filter(lambda line: '1' in line, p))
n = len(p)

if n == 0:
    print(0)
    exit(0)

left = [line.find('1') for line in p]
right = [line.rfind('1') for line in p]

ans = float('inf')
for mask in range(2 ** n):
    cur_res = 0
    prev = 1
    for i in range(n):
        go_left = mask & (1 << i)
        if go_left and prev:
            cur_res += 2 * right[i]
        elif (go_left and not prev) or (not go_left and prev):
            cur_res += m - 1
        elif not go_left and not go_left:
            cur_res += 2 * (m - 1 - left[i])
        if i == n - 1:
            if go_left and prev:
                cur_res -= right[i]
            elif not go_left and not prev:
                cur_res -= m - 1 - left[i]
            elif go_left and not prev:
                cur_res -= left[i]
            elif not go_left and prev:
                cur_res -= m - 1 - right[i]
        prev = go_left
    ans = min(ans, cur_res)

print(ans + addition)
