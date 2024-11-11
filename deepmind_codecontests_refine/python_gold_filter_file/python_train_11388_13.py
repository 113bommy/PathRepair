n =  int(input())
a = input().strip().split(' ')
a =  [int(ai) for ai in a]

count = dict.fromkeys(set(a), 0)

for ai in a:
    count[ai] += 1
 
mcount = max(count.values())
if len(count)==1:
    if n==1:
        print('YES')
    else:
        print('NO')
elif mcount-1 > n-mcount:
    print('NO')
else:
    print('YES')
    
    