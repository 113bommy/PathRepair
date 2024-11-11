N = int(input())
A = list(map(int, input().split()))

ans = -1
for i in range(32, -1, -1):
    count = 0
    ans   = -1
    for n in A:
        if (((1 << i) & n) != 0):
            ans = n
            count += 1
    if count == 1:
        break

if ans != -1:
    print(ans, end = ' ')

for n in A:
    if n != ans:
        print(n, end = ' ')
    else:
        ans = -1

