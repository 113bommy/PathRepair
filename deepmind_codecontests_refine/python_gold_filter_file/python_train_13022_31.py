nm = input().split()
n = int(nm[0])
m = int(nm[1])
seg = []
fora = []

def inSeg(x,seg):
    for pontos in seg:
        if x>pontos[0]-1 and x<pontos[1]+1:
            return True;
    return False;

for i in range(n):
    seg.append(input().split())
    seg[i] = [int(x) for x in seg[i]]
    
for x in range(1,m+1):
    esta = inSeg(x,seg)
    if esta == False:
        fora.append(x)

print(len(fora))
if len(fora)>0:
    for num in fora:
        print(num,end=" ")
