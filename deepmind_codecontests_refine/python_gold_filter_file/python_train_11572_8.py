n=int(input())
a=input()
b=input()

a1 = [[]for i in range(26)]
b1 = [[] for i in range(26)]
q1=[]
q2 = []

for i in range(n):
    if a[i]=='?':
        q1.append(i+1)
    else:
        a1[ord(a[i])-97].append(i+1)
    if b[i]=='?':
        q2.append(i+1)
    else:
    
        b1[ord(b[i])-97].append(i+1) 
ans=[]
resta=[]
restb=[]
ll=[]
xx=[]
for i in range(26):
    for j in range(min(len(a1[i]),len(b1[i]))):
        ans.append([a1[i][j],b1[i][j]])
    for j in range(min(len(a1[i]),len(b1[i])),len(a1[i])):
        resta.append(a1[i][j])
    for j in range(min(len(a1[i]),len(b1[i])),len(b1[i])):
        restb.append(b1[i][j])
for i in range(min(len(resta),len(q2))):
    ans.append([resta[i],q2[i]])
for i in range(min(len(q2),len(resta)),len(q2)):
    ll.append(q2[i])
    
for i in range(min(len(restb),len(q1))):
    ans.append([q1[i],restb[i]])
for i in range(min(len(q1),len(restb)),len(q1)):
    
    xx.append(q1[i])
for i in range(min(len(ll),len(xx))):
    ans.append([xx[i],ll[i]])
print(len(ans))
for i in range(len(ans)):
    print(*ans[i])     
        
    

