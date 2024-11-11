inp = input()
n = int(inp.split()[0])
k = int(inp.split()[1])
for i in range(k):
    if n % 10 == 0:
        n = n//10
    else:
        n -= 1
print(n)