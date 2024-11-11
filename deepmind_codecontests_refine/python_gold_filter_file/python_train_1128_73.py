N = int(input())
a = list(map(int, input().split()))
color = [0] * 9

for i in a:
    color[min(i, 3200) // 400] += 1

x = 8 - color[:-1].count(0)
ans = [max(1, x), x + color[8]]
print(' '.join(map(str, ans)))