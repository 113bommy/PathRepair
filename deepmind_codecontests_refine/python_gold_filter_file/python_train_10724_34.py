x=range(int(input()))
f=lambda a,b,c,d : a*d - b*c 
P=[]
for _ in x:P+=[[int(i) for i in input().split()]]
_=0
P+=[P[0]]
for j in x:_+=f(P[j][0],P[j][1],P[j+1][0],P[j+1][1])
print(_*0.5)