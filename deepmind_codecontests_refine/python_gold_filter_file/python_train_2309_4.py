n = int(input())

elems = [int(elem) for elem in input().split()]
last = float('+inf')
elems = sorted(elems, reverse= True)
ans = 0
for elem in elems:
    if elem + 1 < last:
        ans += 1
        last = elem + 1
    elif elem < last:
        ans += 1
        last = elem
    elif elem - 1 > 0 and elem - 1 < last:
        ans += 1
        last = elem - 1
        
print(ans)