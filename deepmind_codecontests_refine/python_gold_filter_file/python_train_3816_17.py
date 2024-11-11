import re
r,c=map(int,input().split())
s='\n'.join(input().replace('.','D')for _ in[0]*r)
p='.'*c
print('No'if re.search('(?s)(S('+p+')?W)|(W('+p+')?S)',s)else'Yes\n'+s)