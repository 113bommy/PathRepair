s1 = input()
c = input()
m = 0
for i in range(len(c)):
    if s1[m] == c[i]:
        m += 1
print(m+1)