n=int(input())
L=[]
for i in range(n):
    s,p=input().split()
    L.append([s,-int(p),i+1])
for l in sorted(L):
    print(l[2])