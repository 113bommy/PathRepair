n,h,*d=map(int,open(0).read().split());a=max(d[::2]);b=sorted(d[1::2]);c=0
while b and b[-1]>a>0<h:h-=b.pop();c+=1
print(c-(-h//a)*(h>0))