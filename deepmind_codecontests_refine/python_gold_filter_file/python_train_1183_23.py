n , k = map(int, input().split())
a = list(map(int, input().split()))
count = 0
if k > n :
    print('-1')
else:
    while count < k :
        x = y = max(a)
        count += 1
        a.remove(max(a))
    print(x, y)