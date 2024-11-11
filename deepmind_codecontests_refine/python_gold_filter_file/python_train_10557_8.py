n, k = map(int, input().split())
print(' '.join(str(i + 1) + ' ' + str(i) for i in range(1, 2 * k + 1, 2)) + ' ' + ' '.join(str(i) + ' ' + str(i + 1) for i in range(2 * k + 1, 2 * n + 1, 2)))