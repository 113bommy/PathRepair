n, k = map(int, input().split())
l = list(map(int, input().split()))
a = n * [0]
check = n

for i in range(k):
    if a[l[i] - 1] == 0:
        check -= 1
    a[l[i] - 1] += 1
    if check == 0:
        print(1, end = '')
        for j in range(n):
            a[j] -= 1
            if a[j] == 0:
                check += 1
    else:
        print(0, end = '')