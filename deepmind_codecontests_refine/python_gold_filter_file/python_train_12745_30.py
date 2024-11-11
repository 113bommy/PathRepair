a,b,c = map(int,input().split())
x = []
for i in range(1,a+1):
 x.append(i)
if max(b-c,1) != 1: print('<<', end = ' ')
for i in range(max(b-c-1,0),min(b+c,a)):
 if x[i] == b: print('('+str(x[i])+')', end = ' ')
 else: print(x[i], end = ' ')
if min(b+c,a) != a: print('>>')