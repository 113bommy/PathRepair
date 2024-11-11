n = int(input())

den = [100, 20, 10, 5, 1]

i = 0
bills = 0

while n > 0:

    t = n // den[i]

    if t > 0:
        bills += t
        n %= den[i]

    i += 1

#print(n)

print(bills)
