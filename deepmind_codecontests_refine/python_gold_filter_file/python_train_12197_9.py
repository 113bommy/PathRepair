#http://codeforces.com/contest/1166/problem/B
import math
k=int(input())
col=0
row=0
for i in range(5,int(math.sqrt(k))+1):
    if(k%i==0):
        col=i
        row=int(k/col)
        if(row>=5):
            break

def p(r,c):
    output=""
    t=["aeiou","eioua","iouae","ouaei","uaeio"]
    v=["a","e","i","o","u"]
    for i in range(r):
        output=output+t[i%5]
        for j in range(5,c):
            output=output+v[i%5]
    return output
if(row>=5 and col>=5):
    print(p(row,col))    
else:
    print(-1)