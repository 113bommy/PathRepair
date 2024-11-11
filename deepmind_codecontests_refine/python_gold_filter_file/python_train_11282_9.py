n= str(input())
t= str(input())
pos = 0
for i in range(len(t)):
    if t[i] == n[pos]:
        pos=pos+1
    
print(pos+1)