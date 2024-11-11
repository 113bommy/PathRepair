def is_sorted(l):
    return all(a < b for a, b in zip(l[:-1], l[1:]))

n = int(input())
arr = input().split()
arr = list(map(int, arr))
arr = arr[:n]

j = 1
ind1 = 0
ind2 = 0
flag = False
for i in range(1, n):
    if arr[i] == arr[j-1]:
        ind1 = j-1
        ind2 = i
        j -= 1
        flag = True
        break
    j += 1

for i in range(ind1+1, n):
    if arr[ind1] == arr[i]:
        ind2 = i
    else:
        break

if not flag:
    ind1 = arr.index(max(arr))
    ind2 = arr.index(max(arr))

arrIn = arr[:ind1+1]
arrDe = arr[ind2:]
arrDe.reverse()
flag = is_sorted(arrIn) and is_sorted(arrDe)

if flag:
    print('YES')
else:
    print('NO')
