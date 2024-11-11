n = int(input())

if n == 0:
    print(0)
    exit()

s = ""
while n != 0:
    s += str(n%2)
    n = (n-n%2)//(-2)

print(s[::-1])
