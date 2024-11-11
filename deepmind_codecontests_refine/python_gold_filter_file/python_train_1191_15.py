n = int(input())
# n = 3
a = list(map(int, input().split(' ')))
# a = [3, 2, 1]
b = sorted(a)
i = l = r = 0
while i < n:
    if a[i] != b[i]:
        l = i
        break
    i += 1

j = n - 1
while j >= 0:
    if a[j] != b[j]:
        r = j
        break
    j -= 1

if a == b:
    print('yes')
    print('1 1')
elif a[l:r+1][::-1] == b[l:r+1]:
    print('yes')
    print(l+1, r+1)
else:
    print('no')