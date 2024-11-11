n = int(input())

a = [int(s) for s in input().split()]

b = [0]*n

i = n-1
sum = 0
while i > 0:
    sum = max(sum, a[i])
    b[i-1] = max(0, sum + 1 - a[i-1])
    i = i - 1

for elem in b:
    print(elem, end=' ')
