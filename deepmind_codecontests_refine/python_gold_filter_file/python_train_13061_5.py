def shift(num):
    return num[-1]+num[:-1]


def plus_one(num):
    result = ''
    for digit in num:
        new_digit = int(digit)+1
        if new_digit == 10:
            result += '0'
        else:
            result += str(new_digit)
    return result

n = int(input())
num = input()
ans = int(num)
for i in range(10):
    for j in range(n):
        num = shift(num)
        if int(num) < ans:
            ans = int(num)
    num = plus_one(num)
ans = str(ans)
if len(ans) < n:
    ans = '0'*(n-len(ans))+ans
print(ans)
