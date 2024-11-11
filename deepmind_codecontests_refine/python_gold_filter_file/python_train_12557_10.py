n = int(input())
temp = []
for x in range(max(0, n-100), n):
    temp2 = str(x)
    sd = 0
    for i in temp2:
        sd += int(i)
    if sd+x == n:
        temp.append(x)
print(len(temp))
for i in temp:
    print(i)
