n = int(input())

ct = 0
for i in range(1, n):
    ct = (ct + i) % n
    if i == n - 1:
        print(ct + 1, end="")
    else:
        print(ct + 1, end=" ")
