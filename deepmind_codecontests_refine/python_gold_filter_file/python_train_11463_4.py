a,b=map(int,input().split())
limit=1;s=a+b;num=0
while s>=num+limit:
    num+=limit
    limit+=1
limit-=1
a_array=[];b_array=[]
for i in range(limit,0,-1):
    if i<=a:
        a_array.append(i)
        a-=i
    elif i<=b:
        b_array.append(i)
        b-=i
print(len(a_array))
print(*(a_array))
print(len(b_array))
print(*(b_array))

    
