n,h=map(int,input().split())
hs=input()
hs=hs.split()

for i in range(0,len(hs)):
    hs[i]=int(hs[i])
width=0
for ele in hs:
    if ele>h:
        width+=2
    else:
        width+=1

print(width)















