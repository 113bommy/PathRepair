n,c =[int(x) for x in input().split()]
a=[int(x) for x in input().split()] 
#n,c=6,2
#a=[100,1,10,40,10,40]
d=[]
for i in range(n-1):
    for j in range(i+1,i+2):
        d.append(a[i]-a[j])
        
if (max(d)-c>0):
    print(max(d)-c)
else:
    print("0")