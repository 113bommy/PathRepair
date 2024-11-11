import re
S,T=open(0)
S=S.replace('?','.')
T=T[:-1]
s=len(S)
t=len(T)
for i in range(s-t,-1,-1):
 if re.match(S[i:i+t],T):print((S[:i]+T+S[i+t:]).replace('.','a'));exit()
print('UNRESTORABLE')
