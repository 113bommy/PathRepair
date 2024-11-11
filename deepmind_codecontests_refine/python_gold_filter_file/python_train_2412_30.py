r = int(input())
 
if r < 5:
    print("NO")
elif r % 2 == 1:
    print(1, (r-3)//2)
else:
    print("NO")