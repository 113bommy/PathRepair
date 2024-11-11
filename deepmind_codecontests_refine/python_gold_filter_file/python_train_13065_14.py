n = input().split()
total = 0
for i in range(int(n[0])):
    c = input().split()
    for j in range(0,int(n[1])*2,2):
        if int(c[j]) == 1 or int(c[j+1]) == 1:
            total += 1
print(total)   
        
