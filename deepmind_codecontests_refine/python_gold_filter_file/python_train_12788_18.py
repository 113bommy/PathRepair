A, B, C, D, E, F = map(int, input().split(' '))
maxconc = 0.0
maxwater = 100*A
maxsugar = 0

for i in range(F//(100*A)+1):
  for j in range((F-100*A*i)//(100*B)+1):
    if i == 0 and j == 0:
      continue
    S =min(E*(A*i+B*j),F-100*(A*i+B*j))
    
    sugar=0
    for c in range(S//C+1):
      d = (S-c*C)//D
      sugar = max(sugar,c*C+d*D)
    conc = sugar / (sugar +100*(A*i+B*j))
    if conc > maxconc:
      maxconc = conc 
      maxwater = 100*(A*i+B*j)
      maxsugar = sugar
print('{0} {1}'.format(maxwater+maxsugar,maxsugar))    