n = int(input())
name = []
for i in range(n):
    name.append(input())
table = {}
for i in range(n):
    if name[i][0:1] not in table:
        table [name[i][0:1]] = 1
    else:
        table [name[i][0:1]] +=1

#print(table)
res = 0
for key,value in table.items():
  room1 = value//2
  room2 = value - room1
  
  combi = (room1)*(room1-1) /2 + (room2)*(room2-1) /2
  #print(combi)
  res += combi
print(int(res))