n = int(input())

prev, curr = [], []
count = 1
mini = 1

prev = [int(x) for x in input().split()]

for i in range(1,n):
    curr = [int(x) for x in input().split()]

    if prev == curr:
        count +=1
        
    if count > mini:
        mini = count
    
    if prev != curr:
        count = 1
        
    prev = curr
    
print(mini)