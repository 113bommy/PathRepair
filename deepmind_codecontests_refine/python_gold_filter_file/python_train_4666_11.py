ab = []
for i in range(3):
    ab.extend(list(map(int,input().split())))
    
    
for i in range(1,5):
    if ab.count(i) >= 3:
        print("NO")
        exit()
        
print("YES")