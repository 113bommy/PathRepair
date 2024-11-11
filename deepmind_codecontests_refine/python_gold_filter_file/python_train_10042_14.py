n = int(input())
flag = 0
for i in range(1, n + 1):
    if (i * (i + 1)) // 2 == n:
        flag = 1
        print("YES")
        break
if flag == 0:
    print("NO")