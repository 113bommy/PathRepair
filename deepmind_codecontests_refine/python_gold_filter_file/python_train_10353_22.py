
x,amount=map(int,input().strip().split())
l=[]
for i in range(x):
    l.append(list(map(int,input().strip().split())))
items=[]
for i in l:
    items.append(i.pop(0))
business=[]
for i in range(x):
        for k in range(items[0]):
            if(l[i][k]<amount and business.count(i+1)==0):
                business.append(i+1)
        items.pop(0)
if(len(business)==0):
    print(len(business))
else:
    print(len(business))
    print("".join(str(v)+" " for v in business))

       
    