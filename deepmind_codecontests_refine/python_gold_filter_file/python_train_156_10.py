n, k = map(int, input().split(' '))
ids = list(map(int, input(). split(' ')))
cur = 1
while k > cur:
    k -= cur
    cur += 1
print(ids[k-1])