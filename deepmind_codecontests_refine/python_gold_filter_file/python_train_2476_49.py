a, b, c, d = map(int, input().split())

num1 = (a-1)//d
num2 = (c-1)//b

print('Yes' if num1>=num2 else'No')