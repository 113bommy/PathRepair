inp = input().split()
a = int(inp[0])
b = int(inp[1])
i = 0
while(a <= b):
    i += 1
    a = 3 * a
    b = 2 * b
print(i)