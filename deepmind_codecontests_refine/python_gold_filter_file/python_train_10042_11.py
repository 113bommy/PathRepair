x = int(input())
Check = False
for i in range (x+1):
    if (i*(i+1))/2 == x :
        Check = True
print("YES" if Check == True else "NO")