a,b,c,d,e,f= map(int, input().split())
youeki=0
yousitu=0
noudo=0
n_a=int(f/(100*a))


for i in range(1+n_a):
 for j in range(1+int((f-100*i*a)/(100*b))):
  for k in range(1+int((f-100*i*a-100*j*b)/c)):
   for l in range(1+int((f-100*i*a-100*j*b-k*c)/d)):
    S=100.0*a*i+100.0*b*j+c*k+d*l
    T=c*k+d*l
    if S!=0:
     L=100.0*T/S
     if S<=f and L<=100*e/(100+e) and L>=noudo:
      noudo=L
      youeki=S
      yousitu=T
print(int(youeki),int(yousitu))
