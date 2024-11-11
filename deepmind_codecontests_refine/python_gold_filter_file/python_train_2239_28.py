"""
IIIIIIIIII OOOOOOOOOOO IIIIIIIIII
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
IIIIIIIIII OOOOOOOOOOO IIIIIIIIII
"""
a = list(map(int, input().split()))
a.sort()
total = a[0]
if a[0] + a[1] <= a[2]:
	total += a[0] + a[1]
else:
	total += a[2]
if a[1] <= a[2]:
	total += a[1]
else:
	total += a[2] + a[0]
print(total)


