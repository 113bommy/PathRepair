a,v = map(int, input().split())
b,w = map(int, input().split())
T = int(input())
if abs(b-a) <= (v-w)*T:
    print('YES')
else:
    print('NO')