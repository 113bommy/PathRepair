f=lambda s:zip(*[t for t in s if'#'in t])
for r in f(f(open(0).readlines())):print(*r,sep='')