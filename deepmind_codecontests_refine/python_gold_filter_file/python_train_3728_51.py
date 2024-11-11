x,y,z,k=map(int,input().split())
a,b,c=[list(map(int,input().split())) for i in range(3)]
l=sorted([bb+cc for bb in b for cc in c],reverse=1)[:k]
t=sorted([ll+aa for aa in a for ll in l],reverse=1)
for i in range(k):
    print(t[i])