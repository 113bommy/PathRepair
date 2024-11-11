n = int(input())

i = 2
tot = 1
while(i * i <= n):
    if(n % i == 0):
        while(n % i == 0):
            n = n // i
        tot *= i
    i += 1
print(tot * n)