temparr = input()
temparr = temparr.split()
n = int(temparr[0])
m = int(temparr[1])
k = int(temparr[2])
arr =[0 for _ in range(15)]
work = []
leave = []
ans = []
maxsrange = max(n + m , 15) + 1
for i in range(maxsrange):
    if i == 0 :
        for j in range(k):
            ans.append(i + 1)
            work.append(n)
        continue 
    newwork = []
    newleave = []
    for j in work:
        if j == 1:
            newleave.append(m)
            continue 
        newwork.append(j - 1)
    for j in leave:
        if j == 1:
            newwork.append(n)
        newleave.append(j - 1)
    leave = newleave[::]
    work = newwork[::]
    #print(work)
    
    if len(work) == sum(work):
        work.append(n )
        ans.append(i + 1)
    diff = k - len(work)
    if diff > 0 :
        for j in range(diff):
            work.append(n )
            ans.append(i + 1)

print(len(ans))
sans = []
for i in ans:
    sans.append(str(i))
print(" ".join(sans))
    
    
    
    
        
        
        
        
        
        
        