
import sys
#f = open('H:\\Portable Python 3.2.5.1\\test2.txt') 
f = sys.stdin
n = int(f.readline().strip())
people = {}
res = 'YES'
for i in range(n):
    x, k = map(int, f.readline().strip().split())
    #print(x,people)
    if k in people:
        if x==people[k]+1:
            people[k] = x
        elif x<=people[k]:
            pass
        else:
            res='NO'
            break
    else:
        if x==0:
            people[k] = x
        else:
            res='NO'
            break    

print(res)
