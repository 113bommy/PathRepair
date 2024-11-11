n = int(input())
l = "{:b}".format(n)
r = []
for i, c in enumerate(l):
    if c=="1":
        r += [str(len(l)-i)]
print(" ".join(r))
