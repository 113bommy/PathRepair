c=l=0
for x in zip(input(),input()):
 r=x.count('0');l,c=((r,c),(r==l,c+1))[l+r>2]
print(c)