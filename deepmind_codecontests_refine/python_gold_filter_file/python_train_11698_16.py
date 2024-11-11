n = int(input())

a = b = 0
a_success = b_success = 0

for i in range(0, n):
    description = [int(x) for x in input().split()]
    if description[0] == 1:
        a += 1
        a_success += description[1]
    else:
        b += 1
        b_success += description[1]

print(["DEAD", "LIVE"][a_success >= a*5])
print(["DEAD", "LIVE"][b_success >= b*5])

