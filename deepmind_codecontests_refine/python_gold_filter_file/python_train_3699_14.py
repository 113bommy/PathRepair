n   = int(input())
s   = input()
d   = {'B':0,'G':0,'R':0}
for c in s:
    d[c] += 1
vl  = d.values()
b   = max(vl)
s   = min(vl)
ss  = sum(vl)
if   s>0 or (b!=ss and ss-b>1): #(1,1,1) or (2,2,0)
    f = 'BGR'
elif b==ss:             #(1,0,0)
    f = max(d,key=d.get)
elif ss==2 and b==1:    #(1,1,0)
    f = min(d,key=d.get)
else:                   #(2,1,0) 
    f = ''.join([k for k in d if d[k]!=b])
print(f)
