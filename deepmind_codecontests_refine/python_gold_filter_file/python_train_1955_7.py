c=eval('[0]*50,'*50)
r=0
for a in[*open(0)][1:]:
 a=round(float(a)*1e9);x=y=0
 while a%2<1:a//=2;x+=1
 while a%5<1:a//=5;y+=1
 r+=sum(sum(d[max(0,18-y):])for d in c[max(0,18-x):]);c[x][y]+=1
print(r)