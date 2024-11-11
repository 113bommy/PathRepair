f=lambda s:zip(*[t for t in s if'#'in t]);
for r in f(f(__import__('sys').stdin)):print(*r,sep='')