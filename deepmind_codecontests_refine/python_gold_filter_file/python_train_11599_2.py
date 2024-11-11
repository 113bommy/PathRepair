r,c=0,2
for x in input()[::-1]:
  c=[2,c-1][x=='4']
  r=[1,r][c>=0 and x in '14']
r=[r,1][c!=2]
print('YNEOS'[r::2])