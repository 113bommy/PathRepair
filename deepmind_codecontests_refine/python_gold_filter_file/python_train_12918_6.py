n,k=list(map(int,input().split()))
a=list(map(int,input().split()))

biggest=sorted(enumerate(a),key=lambda x: x[1])[-k:]

byIndex=sorted(biggest)

mx=0
groups=[]
start=0
for a,b in byIndex:
    mx+=b
    groups.append(a+1-start)
    start=a+1

groups[-1]-=sum(groups)-n

print(mx)
print(' '.join(map(str,groups)))
    
    

