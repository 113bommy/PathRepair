K = int(input())
A, B = map(int, input().split())
if B - A >= B % K:
    print('OK')
else:
    print('NG')