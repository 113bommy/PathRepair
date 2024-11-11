import re

def do(x, y):
    match = re.search(f"^1*{x}1*$", y)
    # print(x, match)
    if match:
        return True
    else:
        return False

x, y = map(int, input().split())

x1 = bin(x)[2:]
x2 = x1[::-1]

i = 0
while x2[i] == '0':
    i = i + 1

x3 = x2[i:]
x4 = x3[::-1]

if x1[-1] == '0':
    x1 += '1'

y = bin(y)[2:]

# print(x1, x2, x3, x4)
# print(y)

if do(x1, y) or do(x2, y) or do(x3, y) or do(x4, y) or bin(x)[2:] == y:
    print("YES")
else:
    print("NO")

