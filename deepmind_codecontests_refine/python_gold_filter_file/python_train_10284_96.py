k = int(input())
a, b = map(int, input().split())
print('OK' if b // k * k >= a else 'NG')