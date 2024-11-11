inp = input().split()
n = inp[0]
m = int(inp[1])

days = list(map(int, input().split()))

prev = 0
page = 0
residue = 0

for day in days:
    if day + residue >= m:
        page += (day + residue) // m
        residue = (day + residue) % m
        print(str(page - prev), end=" ")
        prev = page
    else:
        residue += day
        print(str(0), end=" ")