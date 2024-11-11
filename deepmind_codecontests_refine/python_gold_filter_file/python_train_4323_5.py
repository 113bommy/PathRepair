n = int(input())
bindigits = []
start = 0
while n>0:
    bindigits.insert(0,n%2)
    n = n // 2
    start += 1

for bit in bindigits:
    if bit == 1:
        print(start, end = ' ')
    start -= 1
