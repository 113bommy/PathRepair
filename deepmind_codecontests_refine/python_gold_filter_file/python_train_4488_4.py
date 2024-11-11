mn=input().split()
m=int(mn[0])
n=int(mn[1])
s=input().strip()
t=[]
p=[chr(i) for i in range(ord('A'),ord('Z')+1)]


t=p[0:n]
for x in t:
    if x not in s:
        print('0')
        exit()
u=dict()
for x in t:
    u[x]=0
for x in s:
    if x in t:
        u[x]+=1
key_min = min(u.keys(), key=(lambda k: u[k]))        
print(u[key_min]*n)    
