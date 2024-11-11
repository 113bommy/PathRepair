n=input()
p='HQ9'
l=[n[i] for i in range(len(n)) if n[i] in p]
if len(l)>0: print('YES')
else: print('NO')