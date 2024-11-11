inputs=[int(x) for x in input().split()]
m=inputs[0] # number of sides
n=inputs[1] # number of tosses
e=0

for i in range(m):
    e+=(i+1)*(((i+1)/m)**n-(i/m)**n)

print(e)