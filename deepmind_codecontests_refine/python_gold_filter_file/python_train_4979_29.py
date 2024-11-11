N, M = map(int, input().split())

if N+M == 15:
    print('+')
elif N*M == 15:
    print('*')
else:
    print('x')