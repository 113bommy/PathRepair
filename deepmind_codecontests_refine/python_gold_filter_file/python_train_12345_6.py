n = int(input())
print('17'[n & 1] + '1' * (n // 2 - 1))