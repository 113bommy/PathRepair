n = list(map(int, input().split()))
y = list(map(int, input().split()))
y_sorted = sorted(y)

team = n[0] // 3
count = 0
d = 2

while team > 0:
    if 5 - y_sorted[d] >= n[1]:
        count += 1
    else:
        break
    team -= 1
    d += 3
print(count)
