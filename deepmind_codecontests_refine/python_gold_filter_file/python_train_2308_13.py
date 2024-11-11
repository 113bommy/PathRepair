a, b, c, d = map(int, input().split())

a = [a, b, c]

for i in range(3):
    for j in range(3-i-1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            
d1 = (a[1]-a[0])
d2 = (a[2]-a[1])

final_d = 0

if (d1 < d):
    final_d += abs(d1-d)
    
    
if (d2 < d):
    final_d += abs(d2-d)
    
print(final_d)