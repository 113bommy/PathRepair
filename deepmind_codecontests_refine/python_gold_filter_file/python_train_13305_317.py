a, b = (int(x) for x in input().split())
print(a+b) if b % a == 0 else print(b-a)