limak,bob=[int(i) for i in input().split()]
year=0
while limak<=bob:
    limak*=3
    bob*=2
    year+=1
print(year)