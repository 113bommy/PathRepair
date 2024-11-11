import sys
dic={"a":1,"b":2,"c":3,"d":4,"e":5,"f":6,"g":7,"h":8}
s=input()
s1=s[0] 
s2=s[1]
s=(dic[s1],int(s2))
e=input()
e1=e[0]
e2=e[1]
e=(dic[e1],int(e2))
xdiffer=s[0]-e[0]
ydiffer=s[1]-e[1]
output=[]
while xdiffer>0:
    output.append("L")
    xdiffer-=1
while ydiffer>0:
    output.append("D")
    ydiffer-=1
while xdiffer<0:
    output.append("R")
    xdiffer+=1
while ydiffer<0:
    output.append("U")
    ydiffer+=1
while "U" in output:
    flag=True
    if "L" in output:
        output.remove("U")
        output.remove("L")
        output.append("LU")
        flag=False
    if "R" in output:
        output.remove("U")
        output.remove("R")
        output.append("RU")
        flag=False
    if flag:
        break
while "D" in output:
    flag=True
    if "L" in output:
        output.remove("D")
        output.remove("L")
        output.append("LD")
        flag=False
    if "R" in output:
        output.remove("D")
        output.remove("R")
        output.append("RD")
        flag=False
    if flag:
        break
print(len(output))
for i in output:
    print(i)
