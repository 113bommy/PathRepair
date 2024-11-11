from collections import Counter
t = int(input())

for i in range(t):
    n = int(input())
    pros = [-1] + list(map(int, input().split()))
    if n < 3:
        print(0,0,0)
        continue
    
    mid = n // 2
    cur = mid
    while(cur >= 1):
        if pros[cur] == pros[mid+1]:
            cur -= 1
        else:
            break
    if cur < 3:
        print(0,0,0)
        continue
    
    counter = Counter(pros[1:cur+1])
    keys = sorted(list(counter.keys()), reverse=True)
    if len(keys) < 3:
        print(0,0,0)
        continue
        
    gold = counter[keys[0]]
    del keys[0]

    silver = 0
    bronze = 0
    
    while(silver <= gold and len(keys) > 0):
        silver += counter[keys[0]]
        del keys[0]
        
    for key in keys:
        bronze += counter[key]

    if silver > gold and bronze > gold and gold > 0:
        print(gold, silver, bronze)
    else:
        print(0,0,0)
        
    
    