ct = input()
lc = input().split()
vrai = "NO"
for i in lc:
    if i[0] == ct[0] or i[1] == ct[1]:
        vrai = "YES"
print(vrai)