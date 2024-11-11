t=int(input())
def possible(presum):
    l=len(presum)
    lastmax=-1
    firstmin=l
    mx=max(presum)
    mn=min(presum)
    for i in range(l):
        if(mx==presum[i]):
            lastmax=max(lastmax,i)
        if(mn==presum[i]):
            firstmin=min(i,firstmin)
    if lastmax<firstmin:
        return True
    return False
for i in range(t):
    s=input()
    l1=[0]
    l2=[0]
    for i in s:
        if i=='S':
            l1.append(l1[-1]-1)
        elif i=='W':
            l1.append(l1[-1]+1)
        elif i=="D":
            l2.append(l2[-1]+1)
        else:
            l2.append(l2[-1]-1)
    length=max(l1)-min(l1)+1
    breadth=max(l2)-min(l2)+1
    ans=length*breadth
    if length>2 and possible(l1):
        ans=min(ans,(length-1)*breadth)
    for i in range(len(l1)):
        l1[i]*=-1
    if length>2 and possible(l1):
        ans=min(ans,(length-1)*breadth)
    if breadth>2 and possible(l2):
        ans=min(ans,(length)*(breadth-1))
    for i in range(len(l2)):
        l2[i]*=-1
    if breadth>2 and possible(l2):
        ans=min(ans,(length)*(breadth-1))
    print(ans)