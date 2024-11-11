A, V = map(int, input().split())
B, W = map(int, input().split())
T=int(input())

if T*(V-W) >= abs(B-A):
    print('YES')
else:
    print('NO')