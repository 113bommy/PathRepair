import sys
input = sys.stdin.readline

N,M,Q=map(int,input().split())
E=[list(map(int,input().split())) for i in range(Q)]

# UnionFind

Group=[i for i in range(N)]# グループ分け.Group[i]=jのときiとjは同じグループ

def find(x):# find(a)=find(b)のとき同じグループ
    while Group[x] != x:
        x=Group[x]
    return x

def Union(x,y):  # xとyが同じグループになるよう更新
    if find(x) != find(y):
        Group[find(y)]=Group[find(x)]=min(find(y),find(x))

E1=[]
for a,b,x in E:
    if x==0:
        Union(a,b)
    else:
        E1.append((a,b))

Group=[find(i) for i in range(N)]

for a,b in E1:
    if Group[a]==Group[b]:
        print("No")
        sys.exit()

C=len(set(Group))

if len(E1)==0:
    if N-1<=M<=(N-C)+C*(C-1)//2:
        print("Yes")
    else:
        print("No")

else:
    if N<=M<=(N-C)+C*(C-1)//2:
        print("Yes")
    else:
        print("No")
    
