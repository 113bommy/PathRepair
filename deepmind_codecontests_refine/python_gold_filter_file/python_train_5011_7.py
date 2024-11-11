n=int(input())
l1=(input())
l2=l1
l1=list(l1)
l2=list(l2)

c={"R","G","B"}
q=0
l1.append("B")
for i in range(n-1):
    
    
    if l1[i]==l1[i+1]:
        tempSet={l1[i],l1[i+1],l1[i+2]}
        Sub=list((c-(c&{l1[i],l1[i+1],l1[i+2]})))
        #print(Sub)
        l1[i+1]=Sub[0]
        q=q+1
l1.pop()
print(q)
print("".join(l1))