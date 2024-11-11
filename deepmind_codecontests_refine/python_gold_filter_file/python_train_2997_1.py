k=int(input())
q=[1,2,3,4,5,6,7,8,9]
for i in range(k):
    l=q[i]
    if l%10!=0:
        q.append(10*l+l%10-1)
    q.append(10*l+l%10)
    if l%10!=9:
        q.append(10*l+l%10+1)
print(l)