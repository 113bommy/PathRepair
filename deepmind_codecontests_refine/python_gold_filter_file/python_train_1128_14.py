n=int(input())
a=list(map(int, input().split()))
b=dict()
for i in a:
    b[i//400]=b.get(i//400,0)+1
count=0
count2=0
for i in b:
    if i>7:count2+=b[i]
    else:count+=1
print(max(count,1),count+count2)