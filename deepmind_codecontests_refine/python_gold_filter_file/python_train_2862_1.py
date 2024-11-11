n, k = map(int, input().split())
arr = []
gc = 0
cus = 0
for i in range(k):
    arr = list(map(int, input().split())) + [10 ** 5 + 2]
    c = 0
    if arr[1] == 1:
        for j in range(1, arr[0] + 1):
            if arr[j] + 1 == arr[j + 1]:
                c += 1
            else:
                break
    cus += arr[0] - c
    gc += arr[0] - c - 1 
print(gc + cus - 1)
    
        
        
            
        
