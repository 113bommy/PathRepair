s=t=0
for _ in[0]*int(input()):a=int(input());s+=(a+t)//2;t=(a+t)%2&(a>0)
print(s)