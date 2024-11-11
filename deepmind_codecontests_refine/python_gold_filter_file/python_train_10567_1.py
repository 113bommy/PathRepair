s = input()
a = list(range(len(s)))
m = int(input())
for i in range(m):
    l, r, k = [int(j) for j in input().split()]
    l -= 1
    k %= r - l
    a[l:r] = a[r - k: r] + a[l:r - k]
for i in a:
    print(s[i], sep = '', end = '')
print()
