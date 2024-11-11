count = 0
quantity = int(input().strip())
buttons = list(map(int, input().strip().split()))
for i in buttons:
    if i == 0:
        count += 1
if count == 0 and len(buttons) == 1:
    print('YES')
elif count != 1 or (count == 1 and len(buttons) == 1):
    print('NO')
else:
    print('YES')