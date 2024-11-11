n = -int(input())
a = ""

while n:
    a+=str(n%2)
    n//=-2

print(a[::-1] if a else 0)