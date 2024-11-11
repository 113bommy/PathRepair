#if n present also remove o and e 
# if z present aso remove e and r and o
zcount=int(0)
ncount=int(0)
output=str("")
length=int(input())
string=str(input())
for i in range(0,length):
    if string[i] == "z":
        zcount=zcount+1
    if string[i] == "n":
        ncount=ncount+1
for i in range(0,ncount):
    output=output+" 1"
for i in range(0,zcount):
    output=output+" 0"
print(output)