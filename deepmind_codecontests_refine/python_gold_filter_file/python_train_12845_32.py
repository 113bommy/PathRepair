n, k = map(int, input().split())
if (2 * k >= n * (n-1)):
    print("no solution")
else:
    print('\n'.join(["{} {}".format(0,i) for i in range(0,n)]))