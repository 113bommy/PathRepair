t = int(input())
a = list(map(int, input().split()))
for i in range(len(a)):
    if a[i] < 15:
        print('NO')
        continue
    a[i] %= 14
    if a[i] <= 6 and a[i] != 0:
        print("YES")
    else:
        print("NO")