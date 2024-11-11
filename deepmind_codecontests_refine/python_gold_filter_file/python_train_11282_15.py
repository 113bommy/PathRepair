
t = input()
c = input()

liss_pos = 0

for a in range(len(c)):
    if c[a] == t[liss_pos]:
        liss_pos += 1

print(liss_pos + 1)