n = int(input())
print("{}:".format(n), end='')
x = int(pow(n, 0.5))+1
for i in range(2, x):
    while n % i == 0:
        print(" {}".format(i), end='')
        n //= i
print(' {}'.format(n) if n != 1 else '')