n = int(input())
i = 1
temp = 0
while ((2**i) - 1)*(2**(i-1)) <= n:
    if n%(((2**i) - 1)*(2**(i-1))) == 0:
        temp = ((2**i) - 1)*(2**(i-1))
    i += 1
print(temp)
