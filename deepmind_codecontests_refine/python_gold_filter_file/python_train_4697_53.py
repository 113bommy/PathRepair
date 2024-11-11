a, b, c = list(map(int, input().split()))
needed = 0
if (a+b-c) <= 0 :
    needed += -(a+b-c-1)
if (a+c-b) <= 0:
    needed += -(a+c-b-1)
if (b+c-a) <= 0:
    needed += -(b+c-a-1)

print(needed)
