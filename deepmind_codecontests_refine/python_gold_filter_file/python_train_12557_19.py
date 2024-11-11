n=int(input())       
a=[]
no=0
i=0
while i<82 and i <=n:
    b=n-i
    b=list(str(b))
    z=0
    for ele in b:
        z+=int(ele)
    if i == z:
        no+=1
        a.append(n-i)
    i+=1
a.sort()
print(no)
for ele in a:
    print(ele)
