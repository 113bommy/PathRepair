I,O,R,J,L,S,Z=map(int,input().split())
a=(I//2+J//2+L//2)*2
b=0
if I*J*L!=0:b=(2*((I-1)//2+(J-1)//2+(L-1)//2)+3)
print(max(a,b)+O)