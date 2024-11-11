x = int (input())
for i in range(1,x+1):
    if x ==i*(i+1)//2 :
        print("YES")
        exit()
print("NO")