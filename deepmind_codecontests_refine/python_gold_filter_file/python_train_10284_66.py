K = int(input())
A, B = map(int, input().split())

if A <= (B // K)*K:
    print('OK')
else:
    print('NG')
