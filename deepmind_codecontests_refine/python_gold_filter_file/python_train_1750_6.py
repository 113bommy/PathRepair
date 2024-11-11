H,W,N=map(int,input().split())
r,c=map(int,input().split())

choku=list(input())
ao=list(input())
choku=choku[::-1]
ao=ao[::-1]

Dwn=1
Up=H
Lef=1
Rgt=W
#print(Dwn,r,Up,Lef,c,Rgt)
def chokudai(c):
    global Dwn
    global Up
    global Lef
    global Rgt
    if choku[c]=="D":
        Dwn+=1
    if choku[c]=='U':
        Up-=1
    if choku[c]=='L':
        Lef+=1
    if choku[c]=='R':
        Rgt-=1
    if Dwn>Up or Lef>Rgt:
        print("NO")
        exit()
#chokudai(0)

def kensho(k):
    global Dwn
    global Up
    global Lef
    global Rgt
    if ao[k]=="U":
        Dwn=max(1,Dwn-1)
    if ao[k]=="D":
        Up=min(H,Up+1)
    if ao[k]=="R":
        Lef=max(1,Lef-1)
    if ao[k]=="L":
        Rgt=min(W,Rgt+1)
#print(Dwn,r,Up,Lef,c,Rgt)
for i in range(N):
    kensho(i)
    #print(Dwn,r,Up,Lef,c,Rgt)
    chokudai(i)
    #print(Dwn,r,Up,Lef,c,Rgt)

if Dwn<=H-r+1 and H-r+1<=Up and Lef<=c and c<=Rgt:
    print("YES")
else:
    print("NO")
    #print(Dwn,r,Up,Lef,c,Rgt)
    