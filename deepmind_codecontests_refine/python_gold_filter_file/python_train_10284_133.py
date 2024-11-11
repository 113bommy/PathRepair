K = int(input())
A, B = map(int, input().split())
if B//K-(A-1)//K>=1:
    print('OK')
else:
    print('NG')