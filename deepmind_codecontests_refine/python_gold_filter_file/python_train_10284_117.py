n = int(input())
a, b = map(int, input().split())
if a <= b//n*n:
    print('OK')
else:
    print('NG')