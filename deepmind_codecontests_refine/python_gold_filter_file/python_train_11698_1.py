n = int(input())
cnt = [0, 0]
for i in range(n):
    a = list(map(int, input().split()))
    cnt[a[0] - 1] += a[1] - a[2]

for elem in cnt:
    if elem >= 0:
        print("LIVE")
    else:
        print("DEAD")



