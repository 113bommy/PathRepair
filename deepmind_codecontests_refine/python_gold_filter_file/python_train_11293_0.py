I=input
R=range
w,h=map(int,I().split())
t=[I()for _ in R(h)]
for r in[[t[i][j]*2for i in R(h)]for j in R(w)]:s=''.join(r);print(s+'\n'+s)