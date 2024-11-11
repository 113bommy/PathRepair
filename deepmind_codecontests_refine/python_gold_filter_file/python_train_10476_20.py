n = str(input())
q = []
a = []
count  = 0
for i in n:
    if i == "A":
        a.append(count)
    if i == "Q":
        q.append(count)
    count += 1

nq = len(q)
na = len(a)

total = 0 

prev = 0
#print(a)
#print(q)
for i in range(nq):
    
    for j in range(prev,na):
        
        if q[i] > a[j]:
            continue
        for u in range(i+1, nq):
            if q[u] < a[j]:
                continue
            else:
                # kk = nq - u 
                total += 1
                #print(kk)
                #break
        #print("jd")
    
    #prev = j

print(total)
        
        