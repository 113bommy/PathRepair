from sys import stdout

n,k = list(map(int,input().split()))

value1,value2 = -1,-1
count1,count2=0,0

for i in range(1,k+2):
    query = ["?"]
    for j in range(1,k+2):
        if i!=j:
            query.append(j)
    print(*query)
    stdout.flush()
    a,b = list(map(int,input().split()))
    if i==1:
        value1 = b
    elif value2==-1 and b!=value1:
        value2=b
    if value1==b:
        count1+=1
    elif value2==b:
        count2+=1

if value1>value2:
    count1,count2=count2,count1

print("!",k+1-count1)