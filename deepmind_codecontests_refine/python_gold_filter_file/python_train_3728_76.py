x,y,z,k=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
AB=[]
for a in A:
    for b in B:
        AB.append(a+b)
AB=sorted(AB,reverse=True)[:k]
ABC=[]
for ab in AB:
    for c in C:
        ABC.append(ab+c)
ABC.sort(reverse=True)
for abc in ABC[:k]:
    print(abc)