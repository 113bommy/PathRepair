t=c=0
for _ in[0]*int(input()):i=int(input());c+=(i+t)//2;t=(i+t)%2&(i>0)
print(c)