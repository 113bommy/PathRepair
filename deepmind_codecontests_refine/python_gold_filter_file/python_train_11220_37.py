N = int(input())
A = list(map(int, input().split()))
A.sort()
a = 1
for i in A:
    a *= i
    if a > 10**18:
        a = -1
        break
print(a)