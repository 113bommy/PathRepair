n = input()
let = input()
z = let.count("z")
nl = let.count("n")
t = z + nl
x = []
for i in range (nl):
    x.append(1)
for i in range (z):
    x.append(0)
s = [str(i) for i in x]
sX = str(" ".join(s))
print(sX)
