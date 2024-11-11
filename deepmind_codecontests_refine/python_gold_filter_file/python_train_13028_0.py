n = int(input())
a = list(map(int, input().split()))
cnt1 = 0
for x in a:
    if x == 1:
        cnt1 += 1
cnt2 = n - cnt1
if n == 1:
    print(*a)
else:
    if cnt1 == 0 or cnt2 == 0:
        print(*a)
    else:
        print("2 1", end=" ")
        cnt1 -= 1
        cnt2 -= 1
        print("2 " * cnt2, end="")
        print("1 " * cnt1)
