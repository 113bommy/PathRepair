S=input()
c=len(S)
k=0
cnt=0
t=''
r=''
for i in S:
    t+=i
    if t==r:
        continue
    r=t
    t=''
    cnt+=1
print(cnt)