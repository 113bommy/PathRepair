al=[0]*13
input()
for i in input().split():
    al[int(i)//400]+=1
tuyoi=sum(al[8:])
iru=sum([1 for a in al[:8] if a > 0])
print(max(1,iru),iru+tuyoi)