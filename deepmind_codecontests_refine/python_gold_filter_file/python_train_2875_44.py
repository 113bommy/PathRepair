n, k = map(int, input().split())
if k == 0 or k == n:
    print('0 0')
elif 3 * k <= n:
    print(1, 2 * k)
else:
    print(1, n - k)

    
