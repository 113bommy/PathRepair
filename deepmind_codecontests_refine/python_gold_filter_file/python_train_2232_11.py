c1, c2 ,c3 ,c4 = map(int, input().split())
 
cal=0
move=input()

for i in range(len(move)):
    if move[i] == "1" :
        cal+=c1 
    elif move[i] == "2" :
        cal+=c2 
    elif move[i]== "3" :
        cal += c3 
    else:
        cal+=c4 
        
        
print(cal)