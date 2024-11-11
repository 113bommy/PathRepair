n, k = map(int, input().split())
m = (n * (n - 1)) // 2
if k < m: print('\n'.join(str(i) + ' ' + str(n * i) for i in range(n)))
else: print('no solution')