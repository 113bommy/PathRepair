num = int(input())
s = list(map(int, list(input())))
arr1 = s[:num]
arr2 = s[num:]
arr1.sort()
arr2.sort()

ii = 0
jj = 0
for i, j in zip(arr1, arr2):
    if i > j:
        ii += 1
    elif j > i:
        jj += 1

if max(ii, jj) == num:
    print("YES")
else:
    print("NO")





