from collections import deque

def getPos (x): 
    return x-1, x+1 

n,m = map (int, input().split()) 
treePos = list(map(int, input().split())) 

occ = dict() 
for pos in treePos : 
    occ[pos] = 0 

q = deque(treePos) 
assigned = 0 
res = 0 
men = list() 

while True : 
    s = q.popleft() 
    d = occ[s] + 1 

    left,right = getPos (s)  
    if left not in occ: 
        assigned += 1 
        men.append (left) 
        occ[left] = d
        q.append (left)
        res += d  

    if assigned == m: 
        break 

    if right not in occ: 
        assigned += 1 
        men.append (right) 
        occ[right] = d 
        q.append (right)
        res += d  
    
    if assigned == m: 
        break 

print (res) 
for man in men : 
    print (man, end=' ') 