
n = int(input())
arr = list(map(int,input().split()))[:n]
pos=0
neg=0
ans = 0
for i in range(n):
    if arr[i] > 0 :
        pos += arr[i]
    elif  arr[i] < 0 and pos >0 :
        pos -= 1
    elif  arr[i] <0:
        neg +=1
        
if neg > 0:
    print(neg)
else:
    print(0)
        
        
