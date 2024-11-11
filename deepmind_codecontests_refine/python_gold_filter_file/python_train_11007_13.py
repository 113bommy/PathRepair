notes = (1,5,10,20,100)

n = int(input())
s = 0
for denom in notes[::-1]:
    s += n // denom
    n %= denom
    if not n:
        break
print(s)