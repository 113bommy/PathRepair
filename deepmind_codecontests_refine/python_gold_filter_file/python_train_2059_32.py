A, V = map(int, input().split())
B, W = map(int, input().split())
T = int(input())
if T * (V - W) >= abs(A - B):
    print('YES')
else:
    print('NO')