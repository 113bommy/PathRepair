A, V = [int(n) for n in input().split()]
B, W = [int(n) for n in input().split()]
T = int(input())
print('YES' if (V-W)*T >= abs(B-A) else 'NO')
