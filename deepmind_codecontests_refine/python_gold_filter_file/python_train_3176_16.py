a = list(map(int,input().split()))

res = 0
for i in range( (10**(a[0]-1)), (10**(a[0]))):
    if i % a[1] == 0:
        res = i
        break

print(res if res != 0 else -1)
    
