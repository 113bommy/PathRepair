a = int(input())
b = int(input())
c = int(input())
max_of = 0

max_of = max(a+b*c, a*(b+c), a*b*c, (a+b)*c, a+b+c)

print(max_of)
