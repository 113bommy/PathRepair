from itertools import combinations
from sys import stdin,stdout

def listIn():
    return list((map(int,stdin.readline().strip().split())))

def stringIn():
    return([x for x in stdin.readline().split()])
    
def intIn():
    return (int(stdin.readline()))


def swap(ans,s):
    if ans[i-1]=="R" :
        if s[i+1]=="G":
            ans[i]="B"
        else:
            ans[i]="G"
    elif ans[i-1]=="B":
        if s[i+1]=="R":
            ans[i]="G"
        else:
            ans[i]="R"
    else:
        if s[i+1]=="B":
            ans[i]="R"
        else:
            ans[i]="B"

n=intIn()
s=stdin.readline()
if n==1:
    print(0)
    print(s)
    exit(0)
if n==2:
    if s[0]!=s[1]:
        print(0)
        print(s)
        exit(0)
    else:
        print(1)
        if s[0]=="R":
            print("RG")
        elif s[0]=="G":
            print("GB")
        else:
            print("BR")
    exit(0)
s=list(s)
ans=s
cnt=0
colors="RGB"
"""
if n==3:
    s1=set(colors)
    s2=s1^set(s)
    s2=list(s2)
    if len(s2)==2:
        print(2)
        ans=str(s[0])+"".join(s2)
    else:
        if s[0]==s[1]:
            ans=s[0]+"".join(s2)+s[2]
        else:
            ans="".join(s[:2]+s2)
        print(1)
    print(ans)
    exit(0)
"""
perms=["RGB","RBG","GBR","GRB","BGR","BRG"]
ans=["000"]
for i in range(6):
    temp=perms[i]*(n//3)+perms[i][:n%3]
    ans.append(temp)
carr=[0]*7
for i in range(n):
    for j in range(1,7):
        if s[i]!=ans[j][i]:
            carr[j]+=1
#print(carr)
cnt=min(carr[1:])
idx=carr.index(cnt)
print(cnt)
print("".join(ans[idx]))

    










