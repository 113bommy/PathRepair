a,b,c=map(int,input().split())
d=0
while (b/a)*100<c:
 b+=1
 d+=1
print(d)