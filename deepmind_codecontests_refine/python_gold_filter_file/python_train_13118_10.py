import sys
d={}
for e in sys.stdin.readlines()[1:]:
 if'f'==e[0]:print('yes'if e[5:]in d else'no')
 else:d[e[7:]]=0
