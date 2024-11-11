n = int(input())
A = list(map(int, input().split()))

if sum(A) != 0:
    print("YES")
    print(1)
    print(1, n)
    exit()

for i in range(1, len(A)):
    sum1 = sum(A[:i])
    sum2 = sum(A[i:])

    if sum1 != 0 and sum2 != 0:
        print("YES")
        print(2)
        print(1, i)
        print(i + 1, n)
        exit()

print("NO")
