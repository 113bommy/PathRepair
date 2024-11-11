n = int(input())
out1 = ""
out2 = ""

for i in range(n):
    if i % 2 == 0:
        out1 += "W"
        out2 += "B"
    else:
        out1 += "B"
        out2 += "W"

for i in range(n):
    if i % 2 == 0:
        print(out1)
    else:
        print(out2)
