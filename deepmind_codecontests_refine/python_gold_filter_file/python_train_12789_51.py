o = input()
e = input()
oe = "".join([i + j for i, j in zip(o,e+"\n")])
print(oe)