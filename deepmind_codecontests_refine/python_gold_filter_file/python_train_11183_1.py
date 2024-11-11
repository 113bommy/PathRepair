'''
    CodeForces 368B
    Fly, Freebies, Fly!
'''

n = int(input())
l = [int(x) for x in input().split()]
T = int(input())
l.sort()

M = 1
inz = 0
fin = 1
count = 1

#print(l)

while fin<n:
    #conta il num max se si parte da inz
    while fin<n and l[fin]-l[inz]<=T:
        count+=1
        fin+=1
    
    #print(count)
    #print(inz)
    #print(fin)
    #print()
    
    if count>M:
        M = count
    
    inz+=1
    count-=1
    if fin<inz:
        fin = inz
        count = 1              

print(M)
