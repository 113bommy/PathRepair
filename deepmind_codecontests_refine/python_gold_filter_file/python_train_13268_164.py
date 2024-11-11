rooms = int(input())
count = 0
for i in range (rooms) :
    p, q = map(int, input().split())
    if abs(p - q) <= 1 :
        count += 0
    else :
#        if p <= q and q <= 2 :
#            count += 0
        if p == q :
            count += 0
        else :
            count += 1
print(count)
