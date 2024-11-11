#v units of money valera has
#n is sellers
#ki no of items of ith seller
#si prices of current seller

n,v = map(int,input().split())
l = []

for i in range(n):
    l1 = list(map(int,input().split()))
    t = l1[1:]
    y = t[:]
    y.sort()
    if(y[0]+1<=v):
        l.append(i+1)
print(len(l))
print(*l)
        

    
