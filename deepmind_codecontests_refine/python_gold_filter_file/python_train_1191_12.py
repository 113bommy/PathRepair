n = int(input())

b = list(map(int, input().split()))
a = b.copy()
b.sort()

l = 0
r = 0
for i in range(n):
    if a[i] != b[i]:
        l = i
        break
for i in range(n-1,-1,-1):
    if a[i] != b[i]:
        r = i
        break

a[l:r+1] = a[l:r+1][::-1]

if a == b:
    print('yes')
    print(l+1, r+1)
else:
    print('no')

