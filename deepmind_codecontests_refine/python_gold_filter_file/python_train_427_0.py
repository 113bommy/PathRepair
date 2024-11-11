n=int(input())
l=input().split()
li=[int(i) for i in l]
hashi=dict()
l=input().split()
li2=[int(i) for i in l]
if(li[0]!=li2[0]):
    print("No")
    quit()
diff1=[li[i+1]-li[i] for i in range(n-1)]
diff2=[li2[i+1]-li2[i] for i in range(n-1)]
for i in diff1:
    if(i in hashi):
        hashi[i]+=1
    else:
        hashi[i]=1
poss=1
for i in diff2:
    if(i not in hashi):
        poss=0
        break
    if(hashi[i]==0):
        poss=0
        break
    hashi[i]-=1
if(poss):
    print("Yes")
else:
    print("No")