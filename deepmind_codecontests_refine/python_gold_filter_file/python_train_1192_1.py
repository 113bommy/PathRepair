direction=str(input())
message=str(input())
keyboard=['q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/']
result=[]
for i in range (len(message)):
  for j in range (len(keyboard)):
    if message[i]==keyboard[j]:
      if direction=="R":
        result.append(keyboard[j-1])
      else:
        result.append(keyboard[j+1])
print((''.join(result)))