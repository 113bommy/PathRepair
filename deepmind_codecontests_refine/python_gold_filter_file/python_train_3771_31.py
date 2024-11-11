def binSearch(a, n):
    i, j = 0, len(a) - 1
    while i != j:
        if (j - i) % 2 == 1:
            if a[i + ((j - i) // 2)] > n:
                i = i + (j - i) // 2 + 1
            else:
                j = i + (j - i) // 2
        else:
            if a[i + (j - i) // 2] > n:
                i = i + (j - i) // 2
            else:
                j = i + (j - i) // 2
    return i

input()
k = ['a']*26
ans = ''
maxColor = 1
for symb in input():
    i = binSearch(k, symb)
    ans += str(i + 1) + ' '
    if i + 1 > maxColor: maxColor = i + 1
    k[i] = symb
print(maxColor)
print(ans)