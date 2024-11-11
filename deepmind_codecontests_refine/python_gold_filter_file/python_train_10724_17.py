x=range(int(input()))
P=[]
for _ in x:P+=[[int(i) for i in input().split()]]
_=0
P+=[P[0]]
for j in x:_+=P[j][0]*P[j+1][1]-P[j][1]*P[j+1][0]
print(_*0.5)