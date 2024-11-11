a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

if (v-w)*t >= abs(a-b):
    print('YES')
else:
    print('NO')