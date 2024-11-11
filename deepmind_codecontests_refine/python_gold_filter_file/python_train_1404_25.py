n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

sum = 0
count = 0
instruments = ''
while sum + min(a) <= k:
    sum += min(a)
    count += 1
    instruments += "%s " % (str(a.index(min(a)) + 1))
    a[a.index(min(a))] = 999999
print(count)
if count > 0:
    print(instruments)