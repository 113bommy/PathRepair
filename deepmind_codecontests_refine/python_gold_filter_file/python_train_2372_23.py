n=int(input())
s=input()
c=s.count
r,g,b=c('R'),c('G'),c('B')
t=0
for i in range(n-2):
  for j in range(i+1,n-1):
    k=j*2-i
    if k<n:
      if s[i]+s[j]+s[k] in ('RGB','RBG','GRB','GBR','BRG','BGR'):
        t+=1
print(r*g*b-t)