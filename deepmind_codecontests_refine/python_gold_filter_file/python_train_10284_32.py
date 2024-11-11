k = int(input())
a, b = map(int, input().split())

if b - b%k >= a:
    print('OK')
else:
    print('NG')