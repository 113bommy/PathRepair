inp = str(input())
c = "+"
for i in inp:
    if c in i:
        inp = inp.replace(c,"")
if len(inp)>1:
    sorte = sorted(inp)
    g = "+".join(sorte)
    print(g)
else:
    print(inp)