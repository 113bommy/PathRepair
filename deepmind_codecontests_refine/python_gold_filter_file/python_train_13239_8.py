s = input()
n = int(s,2)
# print(n)
ct = 0
for i in range(52):
    if 4**i>=n:
        break
    else:
        ct += 1
print(ct)