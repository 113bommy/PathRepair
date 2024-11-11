l=int(input())
a=int(input())
p=int(input())
x=int(a//2)
y=int(p//4)

fl=min(x,y,l)
fa=fl*2
fp=fl*4
s=fl+fa+fp
print(s)