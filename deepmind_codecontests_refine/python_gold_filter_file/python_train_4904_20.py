n = int(input())
if n == 1:
    print("No")
elif n == 2:
    print("No")
else:
    sum_of_n = (n * (n + 1)) // 2
    partition = 0
    for i in range(2, sum_of_n):
        if sum_of_n % i == 0:
            partition = i
            break
    if partition == 0:
        print("No")
    else:
        print("Yes")
        print(1, partition)
        print(n - 1, end=' ')
        for i in range(1, n + 1):
            if partition == i:
                continue
            else:
                print(i, end=' ')
