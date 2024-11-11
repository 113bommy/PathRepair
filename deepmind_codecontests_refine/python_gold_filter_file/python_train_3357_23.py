t = int(input())
l = []

def nNo(l):
    n = l[0]
    k = l[1]
    if k%(n-1)!=0:
        res = n*(k//(n-1))+k%(n-1)
    else :
        res = n*(k/(n-1)) -1
    
    print(int(res))
        
        
for i in range(t):
    l.append(list(map(int,input().split(' '))))
for i in range(t):
    nNo(l[i])