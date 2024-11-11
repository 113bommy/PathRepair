a=int(input())
x=list(map(float,input().split()))
y=list(map(float,input().split()))
d1=0
d2=0
d3=0
for i in range(a):
    d1+=abs(x[i]-y[i])
    d2+=(x[i]-y[i])**2
    d3+=abs((x[i]-y[i])**3)
d22=d2**0.5
d33=d3**(1/3)
print(d1)
print(d22)
print(d33)
print(max([abs(x[i]-y[i]) for i in range(a)]))