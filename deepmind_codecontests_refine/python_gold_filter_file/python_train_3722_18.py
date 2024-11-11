n = int(input())
s = '0'
i = 1
while (int(s) <= n):
    s = bin(i)[2:]
    #print(s)
    i += 1
print(i - 2)