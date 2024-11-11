x, y = map(int, input().split())
num1 = bin(x)[2:]
num2 = bin(y)[2:]
if num2 == num1:
    print("YES")
else:
    ans = ''
    for num in (num1 + '1', str(int(num1[::-1]))[::-1]):
        for i in range(len(num2) - len(num) + 1):
            j = len(num2) - len(num) - i
            if '1' * i + num + '1' * j == num2 or '1' * i + num[::-1] + '1' * j == num2:
                ans = "YES"
    if ans:
        print(ans)
    else:
        print('NO')
