Arr = input()
row = input()
list_Row = row.split()
List = Arr.split()
for R in range(int(List[0])-1):
    n=(input().split())
    list_Row+=n
Color = "#Black&White"
for P in list_Row :
    if (P=="C" or P=="M" or P=="Y"):
        Color = "#Color"    
        
print(Color)
