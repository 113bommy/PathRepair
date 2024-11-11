talika=[]
for _ in range(int(input())):
  shongkha=int(input())
  if shongkha%2==0:
    talika.append(int((shongkha/2)-1))
  else:
    talika.append(int(shongkha/2))
print(*talika,sep='\n')