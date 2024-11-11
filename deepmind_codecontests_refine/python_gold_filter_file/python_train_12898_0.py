b=[1]*500000
for i in range(3,999,2):
 if b[i//2]:b[i*i//2::i]=[0]*len(b[i*i//2::i])
def p(x):
 if x<5*1e5:return b[x]
 x=2*x+1
 for i in range(3,int(x**.5+1),2):
  if x%i==0:return 0
 return 1
print(sum(p(int(input()))for _ in[0]*int(input())))
