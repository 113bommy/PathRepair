n = int(input())
A, B = [], []
p = q = 0
k = n//2

for i in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

for i in range(n):
    if A[p] < B[q]:
        p += 1
    else:
        q += 1

for i in range(n):
        print(1 if i < p or i < k else 0, end='')
print()
for i in range(n):
        print(1 if i < q or i < k else 0, end='')
print()
