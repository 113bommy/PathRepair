n = int(input())

A = [int(i) for i in input().split()]
k = len(str(A[0]))
sum = 0
for i in A:
    for index, c in enumerate(str(i)[::-1]):
        l = int(c)
        sum += (l + 10*l) * 10**(index*2)
sum *= n
print(sum % 998244353)
