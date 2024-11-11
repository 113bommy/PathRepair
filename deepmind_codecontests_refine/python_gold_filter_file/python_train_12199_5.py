s=input()
t=input()
sl,tl=len(s),len(t)
left=[]
right=[]
x=0
for i in range(sl):
    if x<tl and s[i]==t[x]:
        left.append(i)
        x+=1
x=tl-1
for i in range(sl-1,-1,-1):
    if x>=0 and s[i]==t[x]:
        right.append(i)
        x-=1
right.reverse()
if(tl==1):
    print(max(max(left[0],sl-left[0]-1),max(right[0],sl-right[0]-1)))
else:
    ans=max(sl-left[-1]-1,right[0])
    for i in range(1,tl):
        ans=max(ans,right[i]-left[i-1]-1)
    print(ans)