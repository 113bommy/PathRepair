K = int(input())
a, b = map(int, input().split())

if a <= b // K * K:
    print('OK')
else:
    print('NG')