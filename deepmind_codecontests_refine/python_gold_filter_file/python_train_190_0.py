s=input()
ans=0
count=0
for i in s:
    if i=='S':count=max(1,count+1)
    else:count-=1
    if count<0:ans+=1
print(ans*2)