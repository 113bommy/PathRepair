a, b = map(int, input().split())
# print(f'{a} {a+1}' if a-b==8 else -1 if abs(a-b) > 1 else f'{a}0 {a}1' if a == b else f'{a} {b}')
if a == 9 and b == 1:
    print('9 10')
elif b-a == 1:
    print(f'{a} {b}')
elif a == b:
    print(f'{a}0 {a}1')
else:
    print(-1)